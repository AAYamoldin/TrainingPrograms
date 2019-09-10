class Book
  def initialize
    @hh = {}#переменная доступная только внутри класса
  end
  def add_person options
    puts "Already exist!" if @hh[options[:name]]
    @hh[options[:name]] = options[:age]
  end
  def show_all
    @hh.each do |key, value|
      age = @hh[key]
      puts "Name #{key} and age #{age}"
    end
  end
  def show_hesh
    return @hh
  end
end
b = Book.new
b.add_person :name => "Walt", :age => 50# передача параметров как хэш
b1 = Book.new
b1.add_person :name => "Lol", :age => 4654
b.show_all
puts b1.show_hesh.inspect
