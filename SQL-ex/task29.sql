/*В предположении, что приход и расход денег на каждом пункте приема фиксируется не чаще одного раза в день [т.е. первичный ключ (пункт, дата)], 
написать запрос с выходными данными (пункт, дата, приход, расход). 
Использовать таблицы Income_o и Outcome_o.*/

SELECT tmp.point, tmp.date, inc, out FROM 
(SELECT Income_o.point, Income_o.date FROM Income_o
UNION ALL
SELECT Outcome_o.point, Outcome_o.date FROM Outcome_o) tmp
LEFT JOIN Income_o ON tmp.point=Income_o.point AND tmp.date=Income_o.date
LEFT JOIN Outcome_o ON tmp.point=Outcome_o.point AND tmp.date=Outcome_o.date
GROUP BY tmp.point, tmp.date, inc, out