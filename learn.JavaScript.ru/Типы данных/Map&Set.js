// Фильтрация уникальных элементов массива
// важность: 5
// Допустим, у нас есть массив arr.
//
// Создайте функцию unique(arr), которая вернёт массив уникальных, не повторяющихся значений массива arr.
//
// Например:

function unique(arr) {
  /* ваш код */
  uniqarr = Array.from(new Set(arr))
  return uniqarr
}

let values = ["Hare", "Krishna", "Hare", "Krishna",
  "Krishna", "Krishna", "Hare", "Hare", ":-O"
];

alert( unique(values) ); // Hare, Krishna, :-O


// Отфильтруйте анаграммы
// важность: 4
// Анаграммы – это слова, у которых те же буквы в том же количестве, но они располагаются в другом порядке.
//
// Например:
//
// nap - pan
// ear - are - era
// cheaters - hectares - teachers
// Напишите функцию aclean(arr), которая возвращает массив слов, очищенный от анаграмм.
//
// Например:

function aclean(arr){
map = new Map();
arr.map(item => map.set(item.toUpperCase().split("").sort().join("") , item))
return Array.from(map.values())
}
let arr = ["nap", "teachers", "cheaters", "PAN", "ear", "era", "hectares"];

alert( aclean(arr) ); // "nap,teachers,ear" or "PAN,cheaters,era"
// Из каждой группы анаграмм должно остаться только одно слово, не важно какое.
