// Создание калькулятора при помощи конструктора
// важность: 5
// Создайте функцию-конструктор Calculator, который создаёт объекты с тремя методами:
//
// read() запрашивает два значения при помощи prompt и сохраняет их значение в свойствах объекта.
// sum() возвращает сумму введённых свойств.
// mul() возвращает произведение введённых свойств.
// Например:
//
// let calculator = new Calculator();
// calculator.read();
//
// alert( "Sum=" + calculator.sum() );
// alert( "Mul=" + calculator.mul() );

function Calculator(){
  this.read = function() {
    this.arg1 = +prompt(" введите первое значение", '');
    this.arg2 = +prompt(" введите второе значение", '');
  };
  this.sum = function(){
    return this.arg1 + this.arg2
  };
  this.mul = function(){
    return this.arg1 * this.arg2
  };
}

// Создаём Accumulator
// важность: 5
// Напишите функцию-конструктор Accumulator(startingValue).
//
// Объект, который она создаёт, должен уметь следующее:
//
// Хранить «текущее значение» в свойстве value. Начальное значение устанавливается в аргументе конструктора startingValue.
// Метод read() использует prompt для получения числа и прибавляет его к свойству value.
// Таким образом, свойство value является текущей суммой всего, что ввёл пользователь при вызовах метода read(), с учётом начального значения startingValue.
//
// Ниже вы можете посмотреть работу кода:
//
// let accumulator = new Accumulator(1); // начальное значение 1
//
// accumulator.read(); // прибавит ввод prompt к текущему значению
// accumulator.read(); // прибавит ввод prompt к текущему значению
//
// alert(accumulator.value); // выведет сумму этих значений

function Accumulator(startingValue){

  function Accumulator(startingValue){
    this.value = startingValue;
    this.read = function(){
      this.amount_to_adding = +prompt("сколько ты хочешь прибавлять?",``);
      this.value += this.amount_to_adding;
      return this.total;
    }
  }

  accumulator = new Accumulator(1); // начальное значение 1

  accumulator.read(); // прибавит ввод prompt к текущему значению
  accumulator.read(); // прибавит ввод prompt к текущему значению

  alert(accumulator.value); // выведет сумму этих значений
