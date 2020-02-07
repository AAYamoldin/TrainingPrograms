#!/usr/bin/env python
# coding: utf-8

# In[26]:


import pandas as pd


# In[27]:


money = pd.read_excel("USD_CURRENCY.xlsx")


# In[28]:


money.describe()


# In[29]:


future = 7 # будем предсказывать курс на 7 дней вперед
past = 28 # используя данные о курсе за 28 дней назад


# In[30]:


import sklearn


# In[31]:


money


# In[32]:


values = money.curs


# In[33]:


start = past
end = len(values) - future


# In[37]:


raw_data = []
for i in range(start, end):#берем только данные с которыми можно работать
    past_and_future_values = values[(i-past):(i+future)] #список из 35 элементов относительно текущей строки
    raw_data.append(list(past_and_future_values))
    


# In[38]:


past_columns = []
for i in range(past):
    past_columns.append("past_{}".format(i))
 
future_columns = []
for i in range(future):
    future_columns.append("future_{}".format(i))

future_columns


# In[40]:


df = pd.DataFrame(raw_data, columns = (past_columns + future_columns))
df.head()


# In[41]:


df.shape


# ## тренировочная выборка
# нужна для обучения модели
# по сути это учебник, на ней модель обучеается и знает как жить в дальнейшем

# In[56]:


x = df[past_columns][:-1] #вход модели, то что для предсказания


# In[57]:


y = df[future_columns][:-1]# таргет, то что мы хотим предсказать


# ## тестовая выборка
# на ней мы проверяем качество модели, насколько хорошо она обучилась для модели 
# линейной регрессии

# In[54]:


x_test = df[past_columns][-1:]
y_test = df[future_columns][-1:]


# In[48]:


from sklearn.linear_model import LinearRegression


# In[49]:


LinReg = LinearRegression()


# In[58]:


LinReg.fit(x,y) # обучение модели свелось к этой единственной строке(готовый алогоритм)


# In[64]:


prediction = LinReg.predict(x_test)[0]


# In[65]:


import matplotlib.pyplot as plt


# In[66]:


plt.plot(prediction, label = "prediction")
plt.plot(y_test.iloc[0], label = "real")
plt.legend()


# In[67]:


from sklearn.metrics import mean_absolute_error


# In[68]:


mean_absolute_error(y_test, [prediction])


# In[71]:


from sklearn.neighbors import KNeighborsRegressor


# In[82]:


KNN = KNeighborsRegressor(n_neighbors = 1)


# In[83]:


KNN.fit(x,y)


# In[84]:


prediction = KNN.predict(x_test)[0]


# In[85]:


mean_absolute_error(y_test, [prediction])


# In[86]:


plt.plot(prediction, label = "prediction")
plt.plot(y_test.iloc[0], label = "real")
plt.legend()


# In[87]:


from sklearn.neural_network import MLPRegressor


# In[140]:


MLP = MLPRegressor(max_iter = 5000, hidden_layer_sizes = (100, 100, 100), random_state = 42)


# In[141]:


MLP.fit(x,y)


# In[142]:


prediction = MLP.predict(x_test)[0]


# In[143]:


mean_absolute_error(y_test, [prediction])


# In[144]:


plt.plot(prediction, label = "prediction")
plt.plot(y_test.iloc[0], label = "real")
plt.legend()


# In[ ]:




