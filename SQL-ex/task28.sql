/*Используя таблицу Product, 
определить количество производителей, выпускающих по одной модели.*/

SELECT COUNT(tmp.qty) FROM (
SELECT COUNT(maker) as qty FROM product
GROUP BY maker
HAVING (COUNT(model) = 1)) tmp