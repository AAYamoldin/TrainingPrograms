#!/usr/bin/env python
# coding: utf-8

# # Минимизация негладкой функции

# In[69]:


import numpy as np
import matplotlib.pyplot as plt
import scipy.linalg
from scipy.optimize import minimize, differential_evolution
y = lambda x: np.sin(x/5)*np.exp(x/10)+5*np.exp(-x/2)
x = np.linspace(1,30,30)
fig = plt.subplots()
plt.plot(x,y(x))
k = y(x)
h = lambda x: int(y(x))


# Попробуйте найти минимум функции h(x) с помощью BFGS, взяв в качестве начального приближения x=30. Получившееся значение функции – ваш первый ответ в этой задаче.

# In[55]:


x0 = [30.]
res3 = minimize(h, x0, method='BFGS')
res3 = res3.fun
res3 = round(res3,2)
print(res3)


# Теперь попробуйте найти минимум h(x) на отрезке [1, 30] с помощью дифференциальной эволюции. Значение функции h(x) в точке минимума – это ваш второй ответ в этом задании. Запишите его через пробел после предыдущего.

# In[60]:


bounds = [(1,30)]
result = differential_evolution(h, bounds)
result = result.fun
result


# In[70]:


with open('submission-3.txt', 'w') as f:
    string = str(res3) + ' ' + str(result) 
    f.write(string)


# In[ ]:




