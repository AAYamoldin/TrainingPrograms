arr = []
while 2 + 2 == 4
x = 1;
print "Вы хотите добавить кого-нибудь в список? (Y/N)"
want = gets.strip.capitalize
if want == "Y"
  print "Кого добавить в список? "
  name = gets.strip.capitalize
  arr << name
elsif want == "N"
  arr.each {|name|puts "у #{name.capitalize} порядковый номер #{x}"
  }
puts "у #{name.capitalize} порядковый номер #{x}"
x = x + 1
end
print "Кого удалить? (порядковый номер) "
answer = gets.to_i
arr.delete_at(answer-1)
  if arr.empty?
    exit
  end
end