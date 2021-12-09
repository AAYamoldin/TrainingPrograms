/*Найдите производителей принтеров. Вывести: maker*/
SELECT DISTINCT maker FROM product
WHERE type LIKE 'Printer'