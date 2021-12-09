/*Найдите класс, имя и страну для кораблей из таблицы Ships, имеющих не менее 10 орудий.*/
SELECT Classes.class, name, country FROM Classes
INNER JOIN Ships ON Classes.class = Ships.class
WHERE numGuns >= 10
