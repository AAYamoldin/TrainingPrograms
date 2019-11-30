// Замените код Function Expression стрелочной функцией:
//
//  function ask(question, yes, no) {
//   if (confirm(question)) yes()
//   else no();
// }
//
// ask(
//   "Вы согласны?",
//   function() { alert("Вы согласились."); },
//   function() { alert("Вы отменили выполнение."); }
// );
//


function ask(question, yes, no) {
 if (confirm(question)) yes()
 else no();
}
ask(" вы согласны? ",//вызов фунцкции выще 
() => alert(`U agreed!`),
() => alert(`Canceling executing`)
);
