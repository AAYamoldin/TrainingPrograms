/*Найдите производителей, выпускающих по меньшей мере три различных модели ПК. 
Вывести: Maker, число моделей ПК.*/

SELECT maker, COUNT(distinct model) FROM product
WHERE type LIKE 'pc'
GROUP BY maker
HAVING COUNT(distinct model) >= 3