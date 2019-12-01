// Напишите код, выполнив задание из каждого пункта отдельной строкой:
//
// Создайте пустой объект user.
// Добавьте свойство name со значением John.
// Добавьте свойство surname со значением Smith.
// Измените значение свойства name на Pete.
// Удалите свойство name из объекта.
let user = {};
user["name"] = "John";
user["surname"] = "Smith";
user["name"] = "Pete";
delete user.name

// Проверка на пустоту
// важность: 5
// Напишите функцию isEmpty(obj), которая возвращает true, если у объекта нет свойств, иначе false.
function isEmpty(obj){
  for (let key in obj){
    return false
  }
     return true
  };

shedule = {};
alert( isEmpty(shedule) );
shedule["8:30"] = "get up";
alert( isEmpty(shedule) );


// Сумма свойств объекта
// важность: 5
// У нас есть объект, в котором хранятся зарплаты нашей команды:
//
let salaries = {
  John: 100,
  Ann: 160,
  Pete: 130
}
// Напишите код для суммирования всех зарплат и сохраните результат в переменной sum. Должно получиться 390.
//
// Если объект salaries пуст, то результат должен быть 0.
let salaries = {
  John: 100,
  Ann: 160,
  Pete: 130
}
// Напишите код для суммирования всех зарплат и сохраните результат в переменной sum. Должно получиться 390.
//
// Если объект salaries пуст, то результат должен быть 0.
function sumOfSalaries(obj){
  let sum = 0;
  for (let key in obj) {
    if (+obj[key] >= 0) {
     sum += obj[key];
  } else {
    alert (`некоректное значение зарплаты у ${key}`);
    return;
  }}
  return sum
}
alert(` суммарная зарплата команды ${sumOfSalaries(salaries)} `);
