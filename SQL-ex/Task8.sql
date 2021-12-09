/*Найдите производителя, выпускающего ПК, но не ПК-блокноты.*/
SELECT DISTINCT maker FROM product
WHERE type LIKE 'PC' 
EXCEPT
SELECT DISTINCT maker FROM product
WHERE type LIKE 'Laptop'
