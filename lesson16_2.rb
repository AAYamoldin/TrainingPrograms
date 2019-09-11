add_10 = lambda {|x| x+1000 }
add_20 = lambda {|x| x+2000}
sub_5 = lambda {|x| x-10}
#если до 300 то +10
# если до 600 +20
# от 600 и вышел -5
hh = {111 => add_10, 222 => add_10, 333  => add_20, 444 => add_20, 555 => add_20, 666 => sub_5,777 => sub_5,888 => sub_5,999 => sub_5}
balance = 1000
counter = 0
while 2 + 2 == 4
x = rand(100..999)
puts "combination #{x}, balance #{balance}"
counter += 1
if hh[x]
  f = hh[x]
  balance = f.call balance
  puts "lambda called"
  puts "you win in #{counter} times your balance #{balance}"
  exit
else
  balance = sub_5.call balance
end

end
