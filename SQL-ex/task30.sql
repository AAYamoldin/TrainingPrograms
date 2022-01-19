/*
В предположении, что приход и расход денег на каждом пункте приема фиксируется
произвольное число раз (первичным ключом в таблицах является столбец code), 
требуется получить таблицу, в которой каждому пункту за каждую дату выполнения
операций будет соответствовать одна строка.
Вывод: point, date, суммарный расход пункта за день (out),
суммарный приход пункта за день (inc).
Отсутствующие значения считать неопределенными (NULL).*/

SELECT tmp.point, tmp.date, SUM(out), SUM(inc) FROM
(SELECT code, point, date FROM Income
UNION ALL
SELECT code, point, date FROM Outcome) tmp
LEFT JOIN Outcome ON tmp.code = Outcome.code and tmp.point = Outcome.point and
tmp.date = Outcome.date
LEFT JOIN Income ON tmp.code = Income.code and tmp.point = Income.point and
tmp.date = Income.date
GROUP BY tmp.point, tmp.date
