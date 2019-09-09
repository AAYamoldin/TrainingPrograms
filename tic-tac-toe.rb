@table = {1 => "-",2 => "-",3 => "-",4 => "-",5 => "-",6 => "-",7 => "-",8 => "-",9 => "-",}
def location_of_cells
  system "clear"
  puts "Расположение ячеек на доске: "
  puts " -7- | -8- | -9- "
  puts " -4- | -5- | -6- "
  puts " -1- | -2- | -3- "
  puts "Текущая ситуация на доске: "
  puts " -#{@table[7]}- | -#{@table[8]}- | -#{@table[9]}- | "
  puts " -#{@table[4]}- | -#{@table[5]}- | -#{@table[6]}- | "
  puts " -#{@table[1]}- | -#{@table[2]}- | -#{@table[3]}- | "
end
def print_game_moves num
    puts "#{@names[num]} делайте Ваш ход!"
end
def game_movies num
  while 2 + 2 == 4
    ans = gets.to_i
  if num == 1 and @table[ans] == "-"
  @table[ans] = "X"
    break
  elsif num == 2 and @table[ans] == "-"
    @table[ans] = "O"
    break
  else
    puts "Эта ячейка уже занята или значение не корректно!"
  end
  end
end
def check_wins
 0.upto(2) do |x|
 if (@table[3*x +1] =="X" and @table[3*x +2] =="X" and @table[3*x +3] == "X") or  (@table[x+1] =="X" and @table[x+1+3] =="X" and @table[x+1+3+3] == "X") or  (@table[1] =="X" and @table[5] =="X" and @table[9] == "X") or  (@table[3] =="X" and @table[5] =="X" and @table[7] == "X")
   puts "Победа, #{@names[1]}"
   return true
 elsif (@table[3*x +1] == "O" and @table[3*x +2] == "O" and @table[3*x +3] == "O") or  (@table[x+1] =="O" and @table[x+1+3] =="O" and @table[x+1+3+3] == "O") or  (@table[1] =="O" and @table[5] =="O" and @table[9] == "O") or  (@table[3] =="O" and @table[5] =="O" and @table[7] == "O")
   puts "Победа, #{@names[2]}"
   return true
 end
 end
  return false
end


@names = {1 => "" "", 2 => ""}
print "Игрок1 введи своё имя: "
@names[1] = gets.strip.capitalize
print "Игрок2 введи своё имя: "
@names[2] = gets.strip.capitalize
puts"определяем кто будет первым ходить!"
10.times do
  print "\\ \r"
  sleep (0.03)
  print "- \r"
  sleep (0.03)
  print"/ \r"
  sleep(0.03)
  print "\\ \r"
  sleep (0.03)
end
first = @names[rand(1..2)]
if @names[1] == first
  index = 1
else
  @names[1], @names[2] = @names[2], @names[1]
end
puts "Первым ходит #{first}"
while 2 + 2 == 4
  num = 1
  location_of_cells
  print_game_moves num
  game_movies num
  location_of_cells
  if @table.has_value?("-") == false
    puts "Ничья! Вы что, все охуели??"
    break
  end
  break if check_wins == true
  num = 2
  print_game_moves num
  game_movies num
  break if check_wins == true
end
