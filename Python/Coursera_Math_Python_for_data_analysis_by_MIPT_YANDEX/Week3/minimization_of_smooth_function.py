#!/usr/bin/env python
# coding: utf-8

# # Задача 1. Минимизация гладкой функции

# Рассмотрим все ту же функцию из задания по линейной алгебре: f(x) = sin(x / 5) * exp(x / 10) + 5 * exp(-x / 2), но теперь уже на промежутке [1, 30]

# In[3]:


import numpy as np
import matplotlib.pyplot as plt
import scipy.linalg
from scipy.optimize import minimize
y = lambda x: np.sin(x/5)*np.exp(x/10)+5*np.exp(-x/2)
x = np.linspace(1,30,30)
fig = plt.subplots()
plt.plot(x,y(x))


# В первом задании будем искать минимум этой функции на заданном промежутке с помощью scipy.optimize. Разумеется, в дальнейшем вы будете использовать методы оптимизации для более сложных функций, а f(x) мы рассмотрим как удобный учебный пример.
# Напишите на Питоне функцию, вычисляющую значение f(x) по известному x. Будьте внимательны: не забывайте про то, что по умолчанию в питоне целые числа делятся нацело, и о том, что функции sin и exp нужно импортировать из модуля math.
# Попробуйте найти минимум, используя стандартные параметры в функции scipy.optimize.minimize (т.е. задав только функцию и начальное приближение). Попробуйте менять начальное приближение и изучить, меняется ли результат. 

# In[24]:


x0 = [2.]
res1 = minimize(y, x0)
res1


# In[26]:


x0 = [2.]
res2 = minimize(y, x0, method='BFGS')
res2 = res2.fun
res2 = round(res2,2)
print(res2)


# In[27]:


x0 = [30.]
res3 = minimize(y, x0, method='BFGS')
res3 = res3.fun
res3 = round(res3,2)
print(res3)


# In[28]:


with open('submission-1.txt', 'w') as f:
    string = str(res2) + ' ' + str(res3)
    f.write(string)


# In[ ]:




