/*Найдите номера моделей и цены всех имеющихся в продаже продуктов (любого типа) производителя B (латинская буква).*/
SELECT product.model, price FROM product
INNER JOIN laptop ON laptop.model = product.model
WHERE maker LIKE 'B'
UNION
SELECT product.model, price FROM product
INNER JOIN printer ON printer.model = product.model
WHERE maker LIKE 'B'
UNION
SELECT product.model, price FROM product
INNER JOIN pc ON pc.model = product.model
WHERE maker LIKE 'B'
