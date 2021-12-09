/*Найдите размеры жестких дисков, совпадающих у двух и более PC. Вывести: HD*/
SELECT hd FROM pc
GROUP BY hd
HAVING COUNT(hd) > 1
