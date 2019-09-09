def show_book book
  book.keys.each do |key|
    age = book[key]
    puts "Name is #{key} age is #{age}"
end
end

book1 = {:mike => 54, :gus => 23, :lol => 22}
show_book book1
book2 = {:puk => 43, :struk => 11}
show_book book2