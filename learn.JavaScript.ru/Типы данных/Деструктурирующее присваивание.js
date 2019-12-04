//
// Максимальная зарплата
// важность: 5
// У нас есть объект salaries с зарплатами:

let salaries = {
  "John": 100,
  "Pete": 300,
  "Mary": 250
};
// Создайте функцию topSalary(salaries), которая возвращает имя самого высокооплачиваемого сотрудника.
//
// Если объект salaries пустой, то нужно вернуть null.
// Если несколько высокооплачиваемых сотрудников, можно вернуть любого из них.
// P.S. Используйте Object.entries и деструктурирование, чтобы перебрать пары ключ/значение.
function topSalary(salaries){
  if(Object.entries(salaries).length == 0){
    return null;
  }else{
[name, salary] =
Object.entries(salaries).sort((a,b) => a[1]-b[1])[Object.entries(salaries).length-1];
return name;
  }
}
