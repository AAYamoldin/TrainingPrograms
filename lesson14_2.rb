class Book
  def initialize
    @hh = {}
  end

  def add_person options
    puts "Already Exist!" if @hh[options[:name]]
    @hh[options[:name]] = options[:age]
  end

  def show_book
    @hh.each do |key, value|
      puts "Name is #{key} age is #{value}"
    end
  end

  def all
  @hh
end

  def last_person
  puts "последняя персона #{@hh.keys[-1]} с возрастом #{@hh.values.last}"
end
end

def adding_person
  print "Введите имя чувака! (Enter for exit!) "
  name = gets.strip.capitalize
 if name == ""
   return name
 end
  print "Введите возраст чувака! "
  age = gets.to_i
  return name, age
end
b = Book.new
while 2 + 2
name, age = adding_person
  break if name == ""
  b.add_person :name => name, :age => age
end
b.last_person
