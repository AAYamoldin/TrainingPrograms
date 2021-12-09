/*Найдите среднюю скорость ПК, выпущенных производителем A.*/
SELECT AVG(speed) FROM pc
INNER JOIN product ON pc.model = product.model
WHERE maker LIKE 'A'
