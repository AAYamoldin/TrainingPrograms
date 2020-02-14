#!/usr/bin/env python
# coding: utf-8

# # Центральная предельная теорема своими руками

# Выбрал полукруговое распределение  https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.semicircular.html#scipy.stats.semicircular

# In[75]:


from scipy.stats import semicircular, norm
import matplotlib.pyplot as plt
import numpy as np


#  Сгенерируйте из него выборку объёма 1000

# In[87]:


a = 0#сдвиг относительно нуля
b = 1#на сколько влево-вправо интервал относительно сдвига
semicircular_rv = semicircular(a, b)#распределение
r = semicircular_rv.rvs(size=1000)#генерация выборки в 1000 из распределения
x = np.linspace(-1,1, 1000)#генерация точек 


# постройте гистограмму выборки и нарисуйте поверх неё теоретическую плотность распределения вашей случайной величины 

# In[88]:


fig, ax = plt.subplots()
ax.plot(x, semicircular_rv.pdf(x), label='semicircular theoretical pdf')#построение графика плотности вероятности
ax.hist(r, density=True, histtype='stepfilled' , label='histogramm')#построение гистограммы по выборке
plt.legend()
plt.ylabel('$fraction of samples\ /f(x)$')
plt.xlabel('$x$')


# при трёх и более значениях n (например, 5, 10, 50) сгенерируйте 1000 выборок объёма n и постройте гистограммы распределений их выборочных средних.

# In[92]:


n_size = [5, 10, 50]#значения выборок
for size in n_size:
    print ('n=%d:' % size)
    r = [np.mean(semicircular_rv.rvs(size=size)) for _ in range(1000)]#среднее значение 1000выборок объема n_size
    mu = 0 #согласно википедии
    sigma = np.sqrt(b**2/(4*size)) #согласно википедии
    norm_rv = norm(loc=mu, scale = sigma)
    pdf = norm_rv.pdf(x)
    plt.hist(r, density=True, histtype='stepfilled', label='histogramm')
    plt.plot(x, pdf, label='theoretical pdf')
    plt.legend()
    plt.ylabel('$fraction of samples\ /\ f(x)$') 
    plt.xlabel('$x$') 
    plt.show() # Показать график


# Опишите разницу между полученными распределениями при различных значениях n. Как меняется точность аппроксимации распределения выборочных средних нормальным с ростом n?

# # C ростом n полученные распределения всё лучше описываются нормальным распределением, таким образом мы подтвердили справедливость центральной предельной теоремы.

# 
