// Вычислить сумму чисел до данного
// важность: 5
// Напишите функцию sumTo(n), которая вычисляет сумму чисел 1 + 2 + ... + n.
//
// Например:
//
// sumTo(1) = 1
// sumTo(2) = 2 + 1 = 3
// sumTo(3) = 3 + 2 + 1 = 6
// sumTo(4) = 4 + 3 + 2 + 1 = 10
// ...
// sumTo(100) = 100 + 99 + ... + 2 + 1 = 5050
// Сделайте три варианта решения:
//
// С использованием цикла.
// Через рекурсию, т.к. sumTo(n) = n + sumTo(n-1) for n > 1.
// С использованием формулы арифметической прогрессии.
// Пример работы вашей функции:
//
// function sumTo(n) { /*... ваш код ... */ }
//
// alert( sumTo(100) ); // 5050


function sumTo(n,variant){
  switch(variant){
    case 1:
    let sum = 0;
      for(let i = 1; i <= n; i++){
        sum += i;
      }
      return sum;
    break;
    case 2:
    if (n == 1){
      return n;
    }else{
      return n + sumTo(n-1,2);
    }
    break;
    case 3:
    return (1 + n)*n/2;
    break
  }
}



// Числа Фибоначчи
// важность: 5
// Последовательность чисел Фибоначчи определяется формулой Fn = Fn-1 + Fn-2. То есть, следующее число получается как сумма двух предыдущих.
//
// Первые два числа равны 1, затем 2(1+1), затем 3(1+2), 5(2+3) и так далее: 1, 1, 2, 3, 5, 8, 13, 21....
//
// Числа Фибоначчи тесно связаны с золотым сечением и множеством природных явлений вокруг нас.
//
// Напишите функцию fib(n) которая возвращает n-е число Фибоначчи.
//
// Пример работы:

function fib(n) {
if (n == 1 || n == 2){
  return 1;
}else {
return (fib(n-2)+(fib(n-1)))
}
}

alert(fib(3)); // 2
alert(fib(7)); // 13
alert(fib(77)); // 5527939700884757


// Вывод односвязного списка
// важность: 5


let list = {
  value: 1,
  next: {
    value: 2,
    next: {
      value: 3,
      next: {
        value: 4,
        next: null
      }
    }
  }
};
// Напишите функцию printList(list), которая выводит элементы списка по одному.

function printList(list){
  let tmp = list;
while(tmp){
  alert(tmp.value);
  tmp = tmp.next;
}
}
