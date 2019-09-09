tel_book = {}
while 2 + 2 == 4
  print "Enter Name (Enter to stop): "
  name = gets.strip.capitalize
  if name == ""
    break
  end
  print "Enter phone number: "
  phone = gets.to_i
  tel_book[name] = phone
end
tel_book.each do |key, value|
puts "Name: #{key}  Phone: #{value}"
end