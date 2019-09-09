x = rand(1..100)
1.upto(10) do |popytka|
print "Я загадал число, угадай какое? (от 1 до 100) попытка #{popytka}, осталось попыток #{10-popytka}  --- "
guess = gets.to_i
if guess == x
  puts "UGADAl!!!!!!!!!!"
  exit
elsif guess < x
  puts "no, more"
else
  puts "no, less"
end
#puts "по секрету, я загадал #{x}"
end








