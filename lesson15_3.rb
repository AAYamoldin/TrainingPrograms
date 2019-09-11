class Animal
  def initialize name
    @name = name
  end
  def run
    puts "#{@name} is Running..."
  end
  def jump
    puts "#{@name} is Jumping..."
  end
end


class Cat < Animal
def initialize
    super "cat"
end
 def meo
   puts "#{@name} mew-mew!"
 end
end

class Dog < Animal
def initialize
  super "dog"
end
  def gav
    puts "#{@name} Gav- Gav!"
  end
end

cat = Cat.new
cat.run
cat.meo
dog = Dog.new
dog.jump
dog.gav