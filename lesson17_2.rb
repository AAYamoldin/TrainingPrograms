class Albukerke
  def initialize actions
    @actions = actions
  end
  def method_missing doing#т.е. возможно использовать данное избегая кучу ифов
    puts "на входе #{doing}"
    value = @actions[doing]
    puts "If you want to #{doing} you must go to #{value}"
  end
end
a = Albukerke.new :cook => "Walt", :trip => "Jessie", :die => "Gus"
puts "What do you want? (cook, trip, die) "
answer = gets.strip
a. send answer