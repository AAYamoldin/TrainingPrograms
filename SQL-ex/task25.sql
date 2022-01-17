/*Найдите производителей принтеров, которые производят ПК с наименьшим объемом RAM 
и с самым быстрым процессором среди всех ПК, имеющих наименьший объем RAM. 
Вывести: Maker
*/

SELECT DISTINCT maker FROM product
WHERE type LIKE 'Printer' AND maker IN (

SELECT maker FROM (SELECT maker, ram, speed FROM product
INNER JOIN pc ON product.model = pc.model
WHERE ram IN (SELECT MIN(ram) FROM pc)) mrs

WHERE speed IN (SELECT MAX(speed) FROM (SELECT speed FROM product
INNER JOIN pc ON product.model = pc.model
WHERE ram IN (SELECT MIN(ram) FROM pc)) tmp))