/*Найдите производителей ПК с процессором не менее 450 Мгц. Вывести: Maker*/
SELECT DISTINCT maker FROM product
INNER JOIN pc ON product.model = pc.model
WHERE pc.speed >= 450