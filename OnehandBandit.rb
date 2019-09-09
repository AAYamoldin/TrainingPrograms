print "Хочешь поиграть? (Y/N)"
answer = gets.strip.capitalize
if answer == "Y"
print "Сколько у тебя денег? "
money = gets.to_i
while 1
print "Дерни за ручку- нажми Enter"
gets
20.times do
  print "\\ \r"
  sleep (0.03)
  print "- \r"
  sleep (0.03)
  print"/ \r"
  sleep(0.03)
end
if money >0
money = money - 10
x = rand(0..9)
y = rand(0..9)
z = rand(0..9)
if x == 0 && y == 0 && z == 0
  puts "Ваш баланс обнулен, баланс = 0, комбинация #{x} #{y} #{z}"
  money = 0;
  exit
elsif x == 6 && y == 6 && z == 6
  money = money/2;
  puts "Ваш баланс #{money},  комбинация #{x} #{y} #{z}"
elsif x == 7 && y == 7 && z == 7
  money = money +70;
  puts "Ваш баланс увеличен на 70 баксов, баланс  #{money}, комбинация #{x} #{y} #{z}"
else
  puts "ты ничего не выигал, твоя комбинация комбинация #{x}#{y}#{z}, твой баланс #{money}"
end
else
  puts "Ты проигрался!"
  exit
end
end
elsif answer == "N"
 puts "ну как хочешь!"
exit
else
  puts "я не понял Вашего желания!"
exit
end