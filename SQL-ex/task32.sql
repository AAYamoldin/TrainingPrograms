/* Одной из характеристик корабля является половина куба калибра его главных орудий (mw).
   С точностью до 2 десятичных знаков определите среднее значение mw для кораблей каждой страны,
   у которой есть корабли в базе данных.*/

SELECT country, cast(avg((power(bore,3)/2)) as numeric(6,2)) as weight FROM (
    select distinct country, class, bore, ship from classes t1 left join outcomes t2 on t1.class=t2.ship
    WHERE ship=class AND ship not in (SELECT name from Ships)
    UNION ALL
    select country, Classes.class, bore, Ships.class from classes left join Ships
    on Classes.class=Ships.class
    ) a
WHERE ship is not NULL
Group by country