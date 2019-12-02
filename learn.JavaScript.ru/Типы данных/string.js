// Сделать первый символ заглавным
// важность: 5
// Напишите функцию ucFirst(str), возвращающую строку str с заглавным первым символом. Например:
//
// ucFirst("вася") == "Вася";

function ucFirst(str) {
  if (Object.is(str, '')){
  alert("введите не пустую строку")
}else{
  return str[0].toUpperCase()+str.slice(1)
}
}

// Проверка на спам
// важность: 5
// Напишите функцию checkSpam(str), возвращающую true, если str содержит 'viagra' или 'XXX', а иначе false.
//
// Функция должна быть нечувствительна к регистру:
//
// checkSpam('buy ViAgRA now') == true
// checkSpam('free xxxxx') == true
// checkSpam("innocent rabbit") == false

function checkSpam(str){
  if (str.toLowerCase().includes('viagra') || str.toUpperCase().includes('XXX') ){
    return true
  }else{
    return false
  }
}

// Усечение строки
// важность: 5
// Создайте функцию truncate(str, maxlength), которая проверяет длину строки str и, если она превосходит maxlength, заменяет конец str на "…", так, чтобы её длина стала равна maxlength.
//
// Результатом функции должна быть та же строка, если усечение не требуется, либо, если необходимо, усечённая строка.
//
// Например:
//
// truncate("Вот, что мне хотелось бы сказать на эту тему:", 20) = "Вот, что мне хотело…"
//
// truncate("Всем привет!", 20) = "Всем привет!"

function truncate(str, maxlength){
  if (str.length > maxlength ){
    return str.substr(0,maxlength-1) + "…"
  }
  else{
    return str
  }
}
