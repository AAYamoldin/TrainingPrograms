/*Найдите модели ПК-блокнотов, скорость которых меньше скорости каждого из ПК.
Вывести: type, model, speed*/
SELECT DISTINCT product.type, laptop.model, laptop.speed FROM laptop
INNER JOIN product ON laptop.model=product.model
WHERE laptop.speed < ALL (SELECT speed FROM pc)