/*Перечислите номера моделей любых типов, 
имеющих самую высокую цену по всей имеющейся в базе данных продукции.*/

WITH max_price AS (
SELECT MAX(price) AS 'price', model FROM laptop
GROUP BY model
UNION ALL
SELECT MAX(price) AS 'price', model FROM printer
GROUP BY model
UNION ALL
SELECT MAX(price) AS 'price', model FROM pc
GROUP BY model)
SELECT model FROM max_price
WHERE price IN (SELECT MAX(price) FROM max_price)
