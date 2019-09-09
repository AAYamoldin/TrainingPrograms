
arr = []
while 2+2 == 4
print "введите ваш любимый цвет (или stop для выхода) "
answer = gets.strip
if answer != "stop"
arr << answer
else
if arr.empty?
puts "вы не ввели цвета"
exit
else
puts arr.reverse.uniq!
exit
end
end
end