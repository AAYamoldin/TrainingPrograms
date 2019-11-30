'use strict';

let login = prompt('введите логин', '');
if (login == "admin"){
  let password = prompt('password?', '');
  if (password == 'admin'){
    alert('welcome!')
  } else if (password === '' || null){
    alert('canceled!')
  }
  else {alert('i dont know u!')}

} else if (login ===  '' || null){
  alert( 'canceled!')}
  else {
    alert('I dont know u!')
  }
