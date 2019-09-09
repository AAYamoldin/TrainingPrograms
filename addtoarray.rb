@arr_total = []
@answer = ""
arr_total1 = []
@x = 0
def add_items
  print "кого добавим в список? "
  @answer = gets.strip.capitalize
  if @answer == ""
    return @arr_total
  else
  arr = []
  print "сколько ему лет? "
  age = gets.strip
  arr << @answer
  arr << age
  @arr_total << arr
  return @arr_total
  end
end
def display_items (name)
  @x = @x + 1
  puts "Имя #{name[0]} ему #{name[1]} лет c порядковым номером #{@x}"
end
while 2 + 2 == 4
  xx = add_items
  if @answer == ""
    break
  end
end
 xx.each do |name|
  display_items(name)
 end