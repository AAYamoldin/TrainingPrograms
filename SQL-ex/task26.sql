/*Найдите среднюю цену ПК и ПК-блокнотов,
 выпущенных производителем A (латинская буква). 
 Вывести: одна общая средняя цена.*/

SELECT AVG(pr) FROM (
SELECT price as pr FROM laptop
INNER JOIN product ON laptop.model = product.model
WHERE maker LIKE 'A'
UNION ALL
SELECT price as pr FROM pc
INNER JOIN product ON pc.model = product.model
WHERE maker LIKE 'A') tmp
