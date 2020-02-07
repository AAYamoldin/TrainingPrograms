#!/usr/bin/env python
# coding: utf-8

# # Дан набор предложений, скопированных с Википедии. Каждое из них имеет "кошачью тему" в одном из трех смыслов:
# 
#    # кошки (животные)
#    # UNIX-утилита cat для вывода содержимого файлов
#    # версии операционной системы OS X, названные в честь семейства кошачьих
# 
# # Ваша задача — найти два предложения, которые ближе всего по смыслу к расположенному в самой первой строке. В качестве меры близости по смыслу мы будем использовать косинусное расстояние.

# Каждая строка в файле соответствует одному предложению. 
# Считайте их, приведите каждую к нижнему регистру с помощью строковой функции lower().
# 
# Произведите токенизацию, то есть разбиение текстов на слова. Для этого можно воспользоваться регулярным выражением, которое считает разделителем любой символ, не являющийся буквой: re.split('[^a-z]', t). Не забудьте удалить пустые слова после разделения.

# In[56]:


import re
import numpy
import scipy.spatial.distance


# In[83]:


with open('sentences.txt') as file:
    strings = file.readlines()
    lower_lines = []
    for line in strings:
        line = line.strip().lower()
        line = re.split('[^a-z]', line)
        line = [x for x in line if x != '']
        lower_lines.append(line)
strings     


# Составьте список всех слов, встречающихся в предложениях. Сопоставьте каждому слову индекс от нуля до (d - 1), где d — число различных слов в предложениях. Для этого удобно воспользоваться структурой dict.

# In[29]:


def uniquewords(list):
    unique_words = {}
    counter = 0
    for line in list:
        for word in line:
            if word not in unique_words.values():
                unique_words[counter] = word
                counter += 1
    return unique_words
unique_words = uniquewords(lower_lines)


# Создайте матрицу размера n * d, где n — число предложений. Заполните ее: элемент с индексом (i, j) в этой матрице должен быть равен количеству вхождений j-го слова в i-е предложение. У вас должна получиться матрица размера 22 * 254.

# In[61]:


number_of_sentences = len(lower_lines)
number_of_uniq_words = len(unique_words)
matrix = numpy.zeros((number_of_sentences, number_of_uniq_words))
for i in range(number_of_sentences):
    for j in range(number_of_uniq_words):
        counter = 0
        for word in lower_lines[i]:
            if word == unique_words[j]:
                counter += 1
        matrix[i,j] = counter  
matrix        


# Найдите косинусное расстояние от предложения в самой первой строке (In comparison to dogs, cats have not undergone...) до всех остальных с помощью функции scipy.spatial.distance.cosine. Какие номера у двух предложений, ближайших к нему по этому расстоянию (строки нумеруются с нуля)? Эти два числа и будут ответами на задание. Само предложение (In comparison to dogs, cats have not undergone... ) имеет индекс 0.

# In[97]:


cosine = []
for i in range(1, number_of_sentences):
    cosine.append(scipy.spatial.distance.cosine(matrix[0], matrix[i]))
sorting = sorted(range(len(cosine)), key=lambda k: cosine[k])
a = sorting[0] + 1
b = sorting[1] + 1
sorting


# Запишите полученные числа в файл, разделив пробелом. Обратите внимание, что файл должен состоять из одной строки, в конце которой не должно быть переноса. Пример файла с решением вы можете найти в конце задания (submission-1.txt).

# In[92]:


with open('submission-1.txt', 'w') as f:
    string = str(a) + ' ' + str(b)
    f.write(string.strip())
print(strings[a].strip())
print(strings[b].strip()) 


# In[ ]:




