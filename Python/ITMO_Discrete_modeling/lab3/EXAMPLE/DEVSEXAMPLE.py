# -*- coding: cp1251 -*-
from DEVS import *
import random
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

maxAngents = 100
arrivalRateMin = 1
arrivalRateMax = 8
service_xk = np.arange(6)+1
service_pk = (0.1, 0.2, 0.3, 0.25, 0.1, 0.05)
custm = stats.rv_discrete(name='custm', values=(service_xk, service_pk))

# ---- Customer Statistics ----
class customerStat:
    def __init__(self):
         self.id = -1
         self.arrivalTime = -1
         self.serviceTime = -1
         self.interArrivalTime = 0
         self.serviceBegins = -1
         self.waitingTimeInQueue = 0
         self.serviceEnds = -1
         self.timeInSystem = -1
         self.idleTimeOfServer = 0
                    
# ---- Arrival Event ----
class ArrivalEvent:
    def __init__(self):
         self.eTime = 0.0
        
    def Execute(self):
        customer = customerStat()
        customer.id = DEVS.newId
        customer.arrivalTime = self.eTime
        if(len(DEVS.stats)>0):
            customer.interArrivalTime = customer.arrivalTime - DEVS.stats[-1].arrivalTime

        print("Time %d"%self.eTime," Arrival Event of agent {0}".format(customer.id))
        if(DEVS.newId<maxAngents-1):       
            NextArrival = ArrivalEvent()
            NextArrival.eTime = self.eTime+random.randint(arrivalRateMin,arrivalRateMax)                
            DEVS.EQ.AddEvent(NextArrival)

        # server is Free
        if (DEVS.serverIdle == True):
            DEVS.serverIdle = False
            print("server is Busy")
            Service = ServiceEvent()      
            serviceTime = custm.rvs()  
            customer.serviceTime = serviceTime
            customer.serviceBegins = self.eTime # current time
            Service.eTime = self.eTime+serviceTime            
            Service.id = customer.id            
            DEVS.EQ.AddEvent(Service)
        # server is Busy
        else:
            # increase waiting line
            DEVS.customerQueue.append(customer.id)
            print("customerQueue = %d"%len(DEVS.customerQueue))

        DEVS.newId = DEVS.newId + 1
        DEVS.stats.append(customer)
        
# ---- Service (END) Event ----
class ServiceEvent:
    def __init__(self):
         self.eTime = 0.0
         self.id = 0
        
    def Execute(self):        
        ind = [i for i,val in enumerate(DEVS.stats) if val.id == self.id][0]
        DEVS.stats[ind].serviceEnds = self.eTime
        DEVS.stats[ind].timeInSystem = DEVS.stats[ind].serviceEnds - DEVS.stats[ind].arrivalTime 
        DEVS.stats[ind].waitingTimeInQueue = DEVS.stats[ind].serviceBegins - DEVS.stats[ind].arrivalTime # 0 without queue
        DEVS.stats[ind].idleTimeOfServer = DEVS.stats[ind].serviceBegins - DEVS.lastServedTime
        
        print("Time %d"%self.eTime,"Service finished")
        if(len(DEVS.customerQueue)>0):
            qid = DEVS.customerQueue.pop(0)
            qind = [i for i,val in enumerate(DEVS.stats) if val.id == qid][0]
            Service = ServiceEvent()
            serviceTime = custm.rvs()  
            Service.eTime = self.eTime+serviceTime
            Service.id = qid
            DEVS.stats[qind].serviceBegins = self.eTime
            DEVS.stats[qind].serviceTime = serviceTime            
            DEVS.EQ.AddEvent(Service)
            print("take new customer from the queue")            
        else:
            DEVS.serverIdle = True
            print("server is Idle (do nothing)")

        DEVS.lastServedTime = self.eTime

# run simulation
AE = ArrivalEvent()
DEVS.EQ.AddEvent(AE)

# simulation attributes
DEVS.customerQueue = []
DEVS.stats = []
DEVS.newId = 0
DEVS.serverIdle = True
DEVS.lastServedTime = 0 # for Idle time

# --- SIMULATION ---
while DEVS.EQ.QueueSize()>0:
    DEVS.ProcessNextEvent()  

# --- STATISTICS ---

#  --- store all in file  --- 
f = open('output.csv','w')
f.write("Id;Interarrival Time;Arrival Time;Service Time;Time Service Begins;Waiting time in Queue;Time Service Ends;Time Customer Spends in System;Idle time of Server\n")
for s in DEVS.stats:
    f.write("{0};{1};{2};{3};{4};{5};{6};{7};{8}\n".format(s.id,s.interArrivalTime,s.arrivalTime,s.serviceTime,s.serviceBegins,s.waitingTimeInQueue,s.serviceEnds,s.timeInSystem,s.idleTimeOfServer))    
f.close()

# 1) Average waiting time in queue
avTimeInQueue = sum([x.waitingTimeInQueue for x in DEVS.stats])/len(DEVS.stats)
print("\nAverage waiting time: {0:.2f}".format(avTimeInQueue))

# 2) Probability that a customer has to wait
probToWait = len([x for x in DEVS.stats if x.waitingTimeInQueue>0])/len(DEVS.stats)
print("\nProbability that a customer has to wait: {0:.2f}".format(probToWait))

# 3) Probability of an Idle server
probIdle = sum([x.idleTimeOfServer for x in DEVS.stats])/DEVS.GlobalTime
print("\nProbability of an Idle server: {0:.2f}".format(probIdle))

# 4) Average service time (theoretical 3.2)
avServiceTime = sum([x.serviceTime for x in DEVS.stats])/len(DEVS.stats)
print("\nAverage service time: {0:.2f}".format(avServiceTime))

# 5) Average time between arrivals (theoretical 4.5)
avTimeBetwArr = sum([x.interArrivalTime for x in DEVS.stats])/(len(DEVS.stats)-1)
print("\nAverage time between arrivals: {0:.2f}".format(avTimeBetwArr))

# 6) Average waiting time for those who wait
numOfCustWhoWait = len([x for x in DEVS.stats if x.waitingTimeInQueue>0])
avTimeWhoWait = sum([x.waitingTimeInQueue for x in DEVS.stats])/numOfCustWhoWait
print("\nAverage waiting time for those who wait: {0:.2f}".format(avTimeWhoWait))

# 7) Average time a customer spends in the system
avTimeInTheSystem1 = sum([x.timeInSystem for x in DEVS.stats])/len(DEVS.stats)
print("\nAverage time a customer spends in the system: {0:.2f}".format(avTimeInTheSystem1))

avTimeInTheSystem2 = avTimeInQueue + avServiceTime
print("\nAverage time a customer spends in the system (alternative): {0:.2f}".format(avTimeInTheSystem2))

def DrawSampleHistogram(R,title,bins=None):
    fig = plt.figure()
    x = np.arange(len(R)) 
    plt.grid()       
    if(bins is None):    
        plt.hist(R, range=None)
    else:
        plt.hist(R, bins=bins, range=None)
    plt.title(title)
    plt.show()

DrawSampleHistogram([x.waitingTimeInQueue for x in DEVS.stats],"Waiting time in queue")