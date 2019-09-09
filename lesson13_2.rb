def show_book book
  puts "======================================="
  book.keys.each do |key|
    age = book[key]
    puts "Name is #{key} age is #{age}"
  end
  puts "======================================="

end

book1 = {:mike => 54, :gus => 23, :lol => 22}
book2 = {:puk => 43, :struk => 11}
# show_book book2
book1.merge! book2
show_book book1

