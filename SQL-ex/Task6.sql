/*Для каждого производителя, выпускающего ПК-блокноты c объёмом жесткого диска не менее 10 Гбайт, найти скорости таких ПК-блокнотов. Вывод: производитель, скорость.*/
SELECT maker, speed FROM laptop
INNER JOIN product ON laptop.model = product.model
WHERE laptop.hd >= 10
GROUP BY maker, speed
