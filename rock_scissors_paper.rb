arr = [:rock, :scissors, :paper]
comp = rand(0..2)
print "введите свой выбор(1 - rock, 2 - scissors, 3 - paper): "
answer = gets.to_i
if comp == 0 and answer == 1
puts "ничья  #{arr[comp]}"
elsif comp == 0 and answer == 2
  puts "победил компьютер, у компютера #{arr[comp]}"
elsif comp == 0 and answer == 3
  puts "победили вы, у компьютера #{arr[comp]}"
  elsif comp == 1 and answer == 1
    puts "вы победили, у компьютера  #{arr[comp]}"
  elsif comp == 1 and answer == 2
    puts "ничья #{arr[comp]}"
  elsif comp == 1 and answer == 3
    puts "вы проиграли, у компьютера #{arr[comp]}"
    elsif comp == 2 and answer == 1
    puts "компьютер выиграл у него #{arr[comp]}"
  elsif comp == 2 and answer == 2
    puts "вы выиграли у компьютера #{arr[comp]}"
  elsif comp == 2 and answer == 3
    puts "ничья #{arr[comp]}"
else
  puts "я не понимаю, что вы ввели!"
end