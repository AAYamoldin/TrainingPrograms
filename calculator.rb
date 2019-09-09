print "введите А: "
A = gets.to_f
print "Введите В: "
B = gets.to_f
print "что будем делать? (+ - * /) "
todo = gets.strip;
if todo == "+"
  puts "result #{A+B}"
end
if todo == "-"
  puts "result #{A-B}"
end
if todo == "*"
  puts "result #{A*B}"
end
if todo == "/" && B == 0
  puts "на ноль делить нельзя!!"
  exit
end
if todo == "/"
  puts "result #{A/B}"
end