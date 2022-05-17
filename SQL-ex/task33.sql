/* Укажите корабли, потопленные в сражениях в Северной Атлантике (North Atlantic). Вывод: ship. */

SELECT ship FROM Outcomes
WHERE result='sunk' and battle='North Atlantic'
