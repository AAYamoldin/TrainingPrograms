#!/usr/bin/env python
# coding: utf-8

# **Корректность проверена на Python 3.6:**
# + numpy 1.15.4
# + pandas 0.23.4

# # Линейная регрессия и стохастический градиентный спуск

# Задание основано на материалах лекций по линейной регрессии и градиентному спуску. Вы будете прогнозировать выручку компании в зависимости от уровня ее инвестиций в рекламу по TV, в газетах и по радио.

# ## Вы научитесь:
# - решать задачу восстановления линейной регрессии
# - реализовывать стохастический градиентный спуск для ее настройки
# - решать задачу линейной регрессии аналитически

# ## Введение
# Линейная регрессия - один из наиболее хорошо изученных методов машинного обучения, позволяющий прогнозировать значения количественного признака в виде линейной комбинации прочих признаков с параметрами - весами модели. Оптимальные (в смысле минимальности некоторого функционала ошибки) параметры линейной регрессии можно найти аналитически с помощью нормального уравнения или численно с помощью методов оптимизации.  

# Линейная регрессия использует простой функционал качества - среднеквадратичную ошибку. Мы будем работать с выборкой, содержащей 3 признака. Для настройки параметров (весов) модели решается следующая задача:
# $$\Large \frac{1}{\ell}\sum_{i=1}^\ell{{((w_0 + w_1x_{i1} + w_2x_{i2} +  w_3x_{i3}) - y_i)}^2} \rightarrow \min_{w_0, w_1, w_2, w_3},$$
# где $x_{i1}, x_{i2}, x_{i3}$ - значения признаков $i$-го объекта, $y_i$ - значение целевого признака $i$-го объекта, $\ell$ - число объектов в обучающей выборке.

# ## Градиентный спуск
# Параметры $w_0, w_1, w_2, w_3$, по которым минимизируется среднеквадратичная ошибка, можно находить численно с помощью градиентного спуска.
# Градиентный шаг для весов будет выглядеть следующим образом:
# $$\Large w_0 \leftarrow w_0 - \frac{2\eta}{\ell} \sum_{i=1}^\ell{{((w_0 + w_1x_{i1} + w_2x_{i2} +  w_3x_{i3}) - y_i)}}$$
# $$\Large w_j \leftarrow w_j - \frac{2\eta}{\ell} \sum_{i=1}^\ell{{x_{ij}((w_0 + w_1x_{i1} + w_2x_{i2} +  w_3x_{i3}) - y_i)}},\ j \in \{1,2,3\}$$
# Здесь $\eta$ - параметр, шаг градиентного спуска.

# ## Стохастический градиентный спуск
# Проблема градиентного спуска, описанного выше, в том, что на больших выборках считать на каждом шаге градиент по всем имеющимся данным может быть очень вычислительно сложно. 
# В стохастическом варианте градиентного спуска поправки для весов вычисляются только с учетом одного случайно взятого объекта обучающей выборки:
# $$\Large w_0 \leftarrow w_0 - \frac{2\eta}{\ell} {((w_0 + w_1x_{k1} + w_2x_{k2} +  w_3x_{k3}) - y_k)}$$
# $$\Large w_j \leftarrow w_j - \frac{2\eta}{\ell} {x_{kj}((w_0 + w_1x_{k1} + w_2x_{k2} +  w_3x_{k3}) - y_k)},\ j \in \{1,2,3\},$$
# где $k$ - случайный индекс, $k \in \{1, \ldots, \ell\}$.

# ## Нормальное уравнение 
# Нахождение вектора оптимальных весов $w$ может быть сделано и аналитически.
# Мы хотим найти такой вектор весов $w$, чтобы вектор $y$, приближающий целевой признак, получался умножением матрицы $X$ (состоящей из всех признаков объектов обучающей выборки, кроме целевого) на вектор весов $w$. То есть, чтобы выполнялось матричное уравнение:
# $$\Large y = Xw$$
# Домножением слева на $X^T$ получаем:
# $$\Large X^Ty = X^TXw$$
# Это хорошо, поскольку теперь матрица $X^TX$ - квадратная, и можно найти решение (вектор $w$) в виде:
# $$\Large w = {(X^TX)}^{-1}X^Ty$$
# Матрица ${(X^TX)}^{-1}X^T$ - [*псевдообратная*](https://ru.wikipedia.org/wiki/Псевдообратная_матрица) для матрицы $X$. В NumPy такую матрицу можно вычислить с помощью функции [numpy.linalg.pinv](http://docs.scipy.org/doc/numpy-1.10.0/reference/generated/numpy.linalg.pinv.html).
# 
# Однако, нахождение псевдообратной матрицы - операция вычислительно сложная и нестабильная в случае малого определителя матрицы $X$ (проблема мультиколлинеарности). 
# На практике лучше находить вектор весов $w$ решением матричного уравнения 
# $$\Large X^TXw = X^Ty$$Это может быть сделано с помощью функции [numpy.linalg.solve](http://docs.scipy.org/doc/numpy-1.10.1/reference/generated/numpy.linalg.solve.html).
# 
# Но все же на практике для больших матриц $X$ быстрее работает градиентный спуск, особенно его стохастическая версия.

# ## Инструкции по выполнению

# **1. Загрузите данные из файла *advertising.csv* в объект pandas DataFrame. [Источник данных](http://www-bcf.usc.edu/~gareth/ISL/data.html).**

# In[125]:


import pandas as pd
adver_data = pd.read_csv('advertising.csv')


# **Посмотрите на первые 5 записей и на статистику признаков в этом наборе данных.**

# In[126]:


# Ваш код здесь
adver_data.head(5)


# In[127]:


# Ваш код здесь
import numpy as np


# **Создайте массивы NumPy *X* из столбцов TV, Radio и Newspaper и *y* - из столбца Sales. Используйте атрибут *values* объекта pandas DataFrame.**

# In[128]:


x = adver_data.values
#print(x[:,0:3])
X = x[:, 0:3]
y = x[:,3] 
print('eto x', X[0:5, :])
print('eto y', y[0:5])


# **Отмасштабируйте столбцы матрицы *X*, вычтя из каждого значения среднее по соответствующему столбцу и поделив результат на стандартное отклонение. Для определенности, используйте методы mean и std векторов NumPy (реализация std в Pandas может отличаться). Обратите внимание, что в numpy вызов функции .mean() без параметров возвращает среднее по всем элементам массива, а не по столбцам, как в pandas. Чтобы произвести вычисление по столбцам, необходимо указать параметр axis.**

# In[129]:


means = X.mean((0))
means


# In[130]:


stds = X.std((0))
stds


# In[131]:


X = (X-means)/stds
print(X[0:5, :])


# **Добавьте к матрице *X* столбец из единиц, используя методы *hstack*, *ones* и *reshape* библиотеки NumPy. Вектор из единиц нужен для того, чтобы не обрабатывать отдельно коэффициент $w_0$ линейной регрессии.**

# In[132]:


adding_col = np.ones(X.shape[0])
adding_col = adding_col.reshape(X.shape[0],1)
X = np.hstack((X, adding_col))
X


# **2. Реализуйте функцию *mserror* - среднеквадратичную ошибку прогноза. Она принимает два аргумента - объекты Series *y* (значения целевого признака) и *y\_pred* (предсказанные значения). Не используйте в этой функции циклы - тогда она будет вычислительно неэффективной.**

# In[149]:


def mserror(y, y_pred):
    return (
    ((y_pred - y)**2)/len(y_pred)).sum()


# **Какова среднеквадратичная ошибка прогноза значений Sales, если всегда предсказывать медианное значение Sales по исходной выборке? Полученный результат, округленный до 3 знаков после запятой, является ответом на *'1 задание'.***

# In[150]:


median_res = adver_data.Sales.quantile(q=0.5)
print(median_res)
answer1 = mserror(median_res, adver_data.Sales)
print(round(answer1, 3))


# **3. Реализуйте функцию *normal_equation*, которая по заданным матрицам (массивам NumPy) *X* и *y* вычисляет вектор весов $w$ согласно нормальному уравнению линейной регрессии.**

# In[151]:


def normal_equation(X, y):
    a = X.T@X
    b = X.T@y
    result = np.linalg.solve(a,b)
    return result


# In[152]:


norm_eq_weights = normal_equation(X, y)
print(norm_eq_weights)


# **Какие продажи предсказываются линейной моделью с весами, найденными с помощью нормального уравнения, в случае средних инвестиций в рекламу по ТВ, радио и в газетах? (то есть при нулевых значениях масштабированных признаков TV, Radio и Newspaper). Полученный результат, округленный до 3 знаков после запятой, является ответом на *'2 задание'*.**

# In[153]:


mean_values = np.array([0,0,0,1]).T
answer2 = mean_values@norm_eq_weights
print(round(answer2, 3))


# **4. Напишите функцию *linear_prediction*, которая принимает на вход матрицу *X* и вектор весов линейной модели *w*, а возвращает вектор прогнозов в виде линейной комбинации столбцов матрицы *X* с весами *w*.**

# In[154]:


def linear_prediction(X, w):
    return X@w


# **Какова среднеквадратичная ошибка прогноза значений Sales в виде линейной модели с весами, найденными с помощью нормального уравнения?
# Полученный результат, округленный до 3 знаков после запятой, является ответом на *'3 задание'***

# In[155]:


answer3 = mserror(y,linear_prediction(X,norm_eq_weights))
print(round(answer3, 3))


# **5. Напишите функцию *stochastic_gradient_step*, реализующую шаг стохастического градиентного спуска для линейной регрессии. Функция должна принимать матрицу *X*, вектора *y* и *w*, число *train_ind* - индекс объекта обучающей выборки (строки матрицы *X*), по которому считается изменение весов, а также число *$\eta$* (eta) - шаг градиентного спуска (по умолчанию *eta*=0.01). Результатом будет вектор обновленных весов. Наша реализация функции будет явно написана для данных с 3 признаками, но несложно модифицировать для любого числа признаков, можете это сделать.**

# In[156]:


def stochastic_gradient_step(X, y, w, train_ind, eta=0.01):
    size_of_matrix = X.shape[0]
    random_string = X[train_ind]
    
    grad0 =  2 /size_of_matrix * ((linear_prediction(random_string,w) - y[train_ind]) * random_string[0])
    grad1 =  2 /size_of_matrix * ((linear_prediction(random_string,w) - y[train_ind]) * random_string[1])
    grad2 =  2 /size_of_matrix * ((linear_prediction(random_string,w) - y[train_ind]) * random_string[2])
    grad3 =  2 /size_of_matrix * ((linear_prediction(random_string,w) - y[train_ind]) * random_string[3])
    return  w - eta * np.array([grad0, grad1, grad2, grad3])


# **6. Напишите функцию *stochastic_gradient_descent*, реализующую стохастический градиентный спуск для линейной регрессии. Функция принимает на вход следующие аргументы:**
# - X - матрица, соответствующая обучающей выборке
# - y - вектор значений целевого признака
# - w_init - вектор начальных весов модели
# - eta - шаг градиентного спуска (по умолчанию 0.01)
# - max_iter - максимальное число итераций градиентного спуска (по умолчанию 10000)
# - max_weight_dist - максимальное евклидово расстояние между векторами весов на соседних итерациях градиентного спуска,
# при котором алгоритм прекращает работу (по умолчанию 1e-8)
# - seed - число, используемое для воспроизводимости сгенерированных псевдослучайных чисел (по умолчанию 42)
# - verbose - флаг печати информации (например, для отладки, по умолчанию False)
# 
# **На каждой итерации в вектор (список) должно записываться текущее значение среднеквадратичной ошибки. Функция должна возвращать вектор весов $w$, а также вектор (список) ошибок.**

# In[157]:


def stochastic_gradient_descent(X, y, w_init, eta=1e-2, max_iter=1e4,
                                min_weight_dist=1e-8, seed=42, verbose=False):
    # Инициализируем расстояние между векторами весов на соседних
    # итерациях большим числом. 
    weight_dist = np.inf
    # Инициализируем вектор весов
    w = w_init
    # Сюда будем записывать ошибки на каждой итерации
    errors = []
    # Счетчик итераций
    iter_num = 0
    # Будем порождать псевдослучайные числа 
    # (номер объекта, который будет менять веса), а для воспроизводимости
    # этой последовательности псевдослучайных чисел используем seed.
    np.random.seed(seed)
        
    # Основной цикл
    while weight_dist > min_weight_dist:
        # порождаем псевдослучайный 
        # индекс объекта обучающей выборки
        random_ind = np.random.randint(X.shape[0])
        w_new = stochastic_gradient_step(X, y, w, random_ind, eta)
        error = mserror(y, linear_prediction(X,w_new))
        errors.append(error)
        weight_dist = np.linalg.norm(w - w_new)
        w = w_new
        iter_num += 1
              
    return w, errors


#  **Запустите $10^5$ итераций стохастического градиентного спуска. Укажите вектор начальных весов *w_init*, состоящий из нулей. Оставьте параметры  *eta* и *seed* равными их значениям по умолчанию (*eta*=0.01, *seed*=42 - это важно для проверки ответов).**

# In[158]:


get_ipython().run_cell_magic('time', '', 'stoch_grad_desc_weights, stoch_errors_by_iter = stochastic_gradient_descent(X, y, [0,0,0,1], eta=1e-2, max_iter=1e4,\n                                min_weight_dist=1e-8, seed=42, verbose=False)\nprint(stoch_grad_desc_weights)')


# **Посмотрим, чему равна ошибка на первых 50 итерациях стохастического градиентного спуска. Видим, что ошибка не обязательно уменьшается на каждой итерации.**

# In[159]:


get_ipython().run_line_magic('pylab', 'inline')
plot(range(50), stoch_errors_by_iter[:50])
xlabel('Iteration number')
ylabel('MSE')


# **Теперь посмотрим на зависимость ошибки от номера итерации для $10^5$ итераций стохастического градиентного спуска. Видим, что алгоритм сходится.**

# In[160]:


get_ipython().run_line_magic('pylab', 'inline')
plot(range(len(stoch_errors_by_iter)), stoch_errors_by_iter)
xlabel('Iteration number')
ylabel('MSE')


# **Посмотрим на вектор весов, к которому сошелся метод.**

# In[161]:


stoch_grad_desc_weights


# **Посмотрим на среднеквадратичную ошибку на последней итерации.**

# In[162]:


stoch_errors_by_iter[-1]


# **Какова среднеквадратичная ошибка прогноза значений Sales в виде линейной модели с весами, найденными с помощью градиентного спуска? Полученный результат, округленный до 3 знаков после запятой, является ответом на *'4 задание'*.**

# In[163]:


answer4 = mserror(y, linear_prediction(X,stoch_grad_desc_weights))
print(round(answer4, 3))


# In[ ]:




