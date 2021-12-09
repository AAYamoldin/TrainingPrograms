/*Найдите номер модели, скорость и размер жесткого диска для всех ПК стоимостью менее 500 дол. Вывести: model, speed и hd*/
SELECT pc.model, pc.speed, pc.hd FROM pc
WHERE pc.price < 500