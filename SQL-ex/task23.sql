/*Найдите производителей, которые производили бы как ПК
со скоростью не менее 750 МГц, так и ПК-блокноты со скоростью не менее 750 МГц.
Вывести: Maker*/

SELECT maker FROM product
INNER JOIN pc ON product.model = pc.model
WHERE pc.speed >= 750
INTERSECT
SELECT maker FROM product
INNER JOIN laptop on product.model = laptop.model
WHERE laptop.speed >= 750
