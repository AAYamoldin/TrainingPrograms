# -*- coding: cp1251 -*-

# Queue of Events
class EventsQueue:
    def __init__(self):
        self.globalTime = 0
        self.MEvents = []
              
    def QueueSize(self):
        return len(self.MEvents)

    def AddEvent(self,MEvent):        
        count =  len(self.MEvents)
        if count == 0:            
            self.MEvents.append(MEvent)
            return 0            

        if(MEvent.eTime >= self.MEvents[count - 1].eTime ):            
            self.MEvents.append(MEvent)
            return 0                                     
        
        for i in range(0,count-1):
            if (MEvent.eTime >= self.MEvents[i].eTime):
                if (MEvent.eTime < self.MEvents[i + 1].eTime):
                    self.MEvents.insert(i + 1, MEvent)
                    return 0

    def ProcessNextEvent(self):                    
        if (len(self.MEvents) == 0):
            return 0
        self.MEvents[0].Execute()
        self.globalTime = self.MEvents[0].eTime        
        del self.MEvents[0]
        
# Discrete Event System Specification
class DEVS:
    EQ = EventsQueue() 
    GlobalTime = 0.0
    def __init__(self):
        pass

    @staticmethod    
    def ProcessNextEvent():        
        DEVS.EQ.ProcessNextEvent()
        DEVS.GlobalTime = DEVS.EQ.globalTime                   