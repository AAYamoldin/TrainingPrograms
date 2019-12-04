// Сумма свойств объекта
// важность: 5
// Есть объект salaries с произвольным количеством свойств, содержащих заработные платы.
//
// Напишите функцию sumSalaries(salaries), которая возвращает сумму всех зарплат с помощью метода Object.values и цикла for..of.
//
// Если объект salaries пуст, то результат должен быть 0.



let salaries = {
  "John": 100,
  "Pete": 300,
  "Mary": 250
};

function sumSalaries(salaries){
  Object.values(salaries).reduce((sum, salary) => sum+salary,0)
}

alert( sumSalaries(salaries) ); // 650



// Подсчёт количества свойств объекта
// важность: 5
// Напишите функцию count(obj), которая возвращает количество свойств объекта:
//
// let user = {
//   name: 'John',
//   age: 30
// };
//
// alert( count(user) ); // 2
// Постарайтесь сделать код как можно короче.
//
// P.S. Игнорируйте символьные свойства, подсчитывайте только «обычные».
let user = {
  name: 'John',
  age: 30
};
function count(user){
  return Object.keys(user).length
}
