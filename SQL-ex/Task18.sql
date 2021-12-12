/*Найдите производителей самых дешевых цветных принтеров. 
Вывести: maker, price*/
SELECT DISTINCT product.maker, printer.price FROM printer
INNER JOIN product ON printer.model = product.model
WHERE color LIKE 'y' AND printer.price IN (SELECT MIN(price) FROM printer 
WHERE color LIKE 'y')