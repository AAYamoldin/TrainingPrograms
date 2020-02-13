#!/usr/bin/env python
# coding: utf-8

# # Центральная предельная теорема своими руками

# Выбрал полукруговое распределение  https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.semicircular.html#scipy.stats.semicircular

# In[13]:


from scipy.stats import semicircular
import matplotlib.pyplot as plt
import numpy as np


#  Сгенерируйте из него выборку объёма 1000

# In[14]:


r = semicircular.rvs(size=1000)
x = np.linspace(semicircular.ppf(0.01),
                semicircular.ppf(0.99), 1000)


# постройте гистограмму выборки и нарисуйте поверх неё теоретическую плотность распределения вашей случайной величины 

# In[24]:


fig, ax = plt.subplots(1, 1)
ax.plot(r, semicircular.pdf(r),
       'r-', lw=5, label='semicircular pdf')


# In[19]:


fig, ax = plt.subplots(1, 1)
rv = semicircular()
ax.plot(r, rv.pdf(r), 'k-', lw=2, label='frozen pdf')


# In[23]:


fig, ax = plt.subplots(1, 1)
ax.hist(r, density=True, histtype='stepfilled')


# In[ ]:




