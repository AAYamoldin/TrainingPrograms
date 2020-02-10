#!/usr/bin/env python
# coding: utf-8

# #  Глобальная оптимизация

# In[3]:


import numpy as np
import matplotlib.pyplot as plt
import scipy.linalg
from scipy.optimize import minimize, differential_evolution
y = lambda x: np.sin(x/5)*np.exp(x/10)+5*np.exp(-x/2)
x = np.linspace(1,30,30)
fig = plt.subplots()
plt.plot(x,y(x))


# In[9]:


bounds = [(1,30)]
result = differential_evolution(y, bounds)
result = round(result.fun[0],2)


# In[10]:


with open('submission-2.txt', 'w') as f:
    string = str(result)
    f.write(string)


# In[ ]:




