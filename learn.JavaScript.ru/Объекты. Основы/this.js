// Создайте калькулятор
// важность: 5
// Создайте объект calculator (калькулятор) с тремя методами:
//
// read() (читать) запрашивает два значения и сохраняет их как свойства объекта.
// sum() (суммировать) возвращает сумму сохранённых значений.
// mul() (умножить) перемножает сохранённые значения и возвращает результат.



let calculator = {
  read() {
    this.arg1 = +prompt("введите первое значение!", '');
    this.arg2 = +prompt("введите второе значение!", '');
  },
   sym(){
    return this.arg1 + this.arg2
  },
  mul(){
    return this.arg1 * this.arg2
  }
};

calculator.read();
alert( calculator.sym() );
alert( calculator.mul() );

// Цепь вызовов
// важность: 2
// Это ladder (лестница) – объект, который позволяет подниматься вверх и спускаться:
//
// let ladder = {
//   step: 0,
//   up() {
//     this.step++;
//   },
//   down() {
//     this.step--;
//   },
//   showStep: function() { // показывает текущую ступеньку
//     alert( this.step );
//   }
// };
// Теперь, если нам нужно сделать несколько последовательных вызовов, мы можем выполнить это так:
//
// ladder.up();
// ladder.up();
// ladder.down();
// ladder.showStep(); // 1
// Измените код методов up, down и showStep таким образом, чтобы их вызов можно было сделать по цепочке, например так:
//
// ladder.up().up().down().showStep(); // 1
// Такой подход широко используется в библиотеках JavaScript.
let ladder = {
  step: 0,
  up() {
    this.step++;
    return this;
  },
  down(){
    this.step--
    return this;
  },
  showStep: function() {
    alert(this.step);
    return this;
  },
}
