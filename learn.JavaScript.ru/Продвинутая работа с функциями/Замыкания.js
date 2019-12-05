// Фильтрация с помощью функции
// важность: 5
// У нас есть встроенный метод arr.filter(f) для массивов. Он фильтрует все элементы с помощью функции f. Если она возвращает true, то элемент добавится в возвращаемый массив.
//
// Сделайте набор «готовых к употреблению» фильтров:
//
// inBetween(a, b) – между a и b (включительно).
// inArray([...]) – находится в данном массиве.
// Они должны использоваться таким образом:
//
// arr.filter(inBetween(3,6)) – выбирает только значения межу 3 и 6 (включительно).
// arr.filter(inArray([1,2,3])) – выбирает только элементы, совпадающие с одним из элементов массива
// Например:

/* .. ваш код для inBetween и inArray */
function inBetween(a,b){
  return function(x){
    return x >= a && x <=b;
  }
}

function inArray(array){
  return function(x){
    return array.includes(x)
  }
}
let arr = [1, 2, 3, 4, 5, 6, 7];

alert( arr.filter(inBetween(3, 6)) ); // 3,4,5,6

alert( arr.filter(inArray([1, 2, 10])) ); // 1,2



// Армия функций
// важность: 5
// Следующий код создаёт массив из стрелков (shooters).
//
// Каждая функция предназначена выводить их порядковые номера. Но что-то пошло не так…
//
//  function makeArmy() {
//   let shooters = [];
//
//   let i = 0;
//   while (i < 10) {
//     let shooter = function() { // функция shooter
//       alert( i ); // должна выводить порядковый номер
//     };
//     shooters.push(shooter);
//     i++;
//   }
//
//   return shooters;
// }
//
// let army = makeArmy();
//
// army[0](); // у 0-го стрелка будет номер 10
// army[5](); // и у 5-го стрелка тоже будет номер 10
// // ... у всех стрелков будет номер 10, вместо 0, 1, 2, 3...
// Почему у всех стрелков одинаковые номера? Почините код, чтобы он работал как задумано.

function makeArmy(){
  let shooters = [];
  for (let i = 0; i <= 10; i++){
    let shooter = function(){
      alert(i);
    }
    shooters.push(shooter);
  }
  return shooters;
}
