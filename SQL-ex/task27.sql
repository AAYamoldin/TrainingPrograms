/*Найдите средний размер диска ПК каждого из тех производителей, которые выпускают и принтеры.
Вывести: maker, средний размер HD.*/

SELECT maker, AVG(hd) FROM pc
INNER JOIN product ON pc.model = product.model
WHERE maker IN (SELECT maker FROM product WHERE type LIKE 'Printer')
GROUP BY maker