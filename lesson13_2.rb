def show_book book
  puts "=======================================<br/>"
  book.keys.each do |key|
    age = book[key]
    puts "Name is <i>#{key}</i> age is <b>#{age}</b> <br/>"
  end
  puts "=======================================<br/>"
end

book1 = {:mike => 54, :gus => 23, :lol => 22}
book2 = {:puk => 43, :struk => 11}
# show_book book2
book1.merge! book2
puts "<body>"
show_book book1

