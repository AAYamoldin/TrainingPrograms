/*Найдите номер модели, скорость и размер жесткого диска ПК, имеющих 12x или 24x CD и цену менее 600 дол.*/
SELECT model, speed, hd FROM pc
WHERE (cd LIKE '12x' OR cd LIKE '24x') AND (price < 600)
