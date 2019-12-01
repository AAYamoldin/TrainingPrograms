winscombination = {111 => 10, 222 => 20, 333 => 30, 444 => 40, 555 => 50, 666 => 60, 777 => 70, 888 => 80, 999 => 90}
print "Сколько у тебя есть денег? "
money = gets.to_i
puts "окей, одна игра стоит 10 баксов"
print "хочешь поиграть, герой? (Y/N) "
want = gets.strip.capitalize
if want == "Y"
  while 2 + 2 == 4
    money = money - 10
    print"Запускай машину, жми Enter! (любая другая кнопка для выхода)"
    start = gets.strip
    if start == ""
      20.times do
        print "\\ \r"
        sleep (0.03)
        print "- \r"
        sleep (0.03)
        print"/ \r"
        sleep(0.03)
      end
      random = rand(100..999)
      if winscombination.key(random)
        money = money + winscombination[random]
      end
      puts "твоя комбинация #{random} твой баланс #{money}"
      if money <= 0
        puts "Застрелись, ты проигрался!"
        exit
      end
    else
      puts "прощай! твой баланс #{money}"
      exit
    end
  end
elsif want == "N"
  puts "ну и проваливай! твой баланс #{money}"
else
  puts "Я тебя не понимаю, обкуренный придурок! "
end
