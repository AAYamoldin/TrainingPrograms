/* Найдите пары моделей PC, имеющих одинаковые скорость и RAM. В результате каждая пара указывается только один раз, т.е. (i,j), но не (j,i), Порядок вывода: модель с большим номером, модель с меньшим номером, скорость и RAM. */
SELECT mm as model, model, speed, ram FROM pc,
(SELECT model as mm, speed as sp, ram as rm FROM pc
) tmp
WHERE sp = speed and rm = ram and mm > model
GROUP BY mm, model, speed, ram
