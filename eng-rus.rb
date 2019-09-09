dic = {:dog => ["собака", "пёс"], :cat => ["кошка", "котяндрий", "кофетерий"], :girl => ["девушка"] }
numelvalues = 0
# while 2 + 2 == 4
#   print "Введите слово (dog, cat, girl): "
#   word = gets.strip.to_sym
#   if word == ""
#     break
#   end
#   puts "колличество перевода слова: #{dic[word].size}"
#   puts "Переводы: "
#   end
#   dic[word].each {|name| puts "#{name}" }
  dic.each_value {|value| numelvalues += value.size}
puts "всего колличество переводов #{numelvalues}"