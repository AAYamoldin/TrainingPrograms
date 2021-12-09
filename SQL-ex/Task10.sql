/*Найдите модели принтеров, имеющих самую высокую цену. Вывести: model, price*/
SELECT model, price FROM printer
WHERE price IN (SELECT MAX(price) FROM printer)