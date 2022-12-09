SELECT DISTINCT name FROM Ships
inner join Classes
ON Ships.class = Classes.class
where launched >= 1922 and launched is not null and displacement > 35000 and displacement is not null and type LIKE 'bb'
