/* Для классов кораблей, калибр орудий которых не менее 16 дюймов, укажите класс и страну.*/

SELECT class, country FROM Classes
WHERE bore >= 16