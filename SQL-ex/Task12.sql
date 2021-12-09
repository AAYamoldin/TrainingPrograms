/*Найдите среднюю скорость ПК-блокнотов, цена которых превышает 1000 дол.*/
SELECT AVG(speed) FROM laptop
WHERE price > 1000
