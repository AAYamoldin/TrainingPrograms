def run_5_times
x = 0
while x < 5
    yield x, 55 #передаем параментр в елд
  x+=1
end
end
run_5_times {|i,v| puts "something!, index: #{i}, value #{v}"}#ловим наш параментр здесь в качестве i