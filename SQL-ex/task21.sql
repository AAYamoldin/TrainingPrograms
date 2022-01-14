/*Найдите максимальную цену ПК, выпускаемых каждым производителем, у которого есть модели в таблице PC.
Вывести: maker, максимальная цена.*/

SELECT maker, max(price) FROM pc
INNER JOIN product ON pc.model = product.model
GROUP BY maker
