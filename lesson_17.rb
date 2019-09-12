class Something
  attr_accessor :x , :y, :z
  def initialize hash
    hash.each do |key, value|
        send "#{key}=", value
    end
  end
  #метод выше альтернатива, используется для инициализации больших хэшей
  # def initialize x,y,z
  # @x = x
  # @y = y
  # @z = z
  # end
end
s = Something.new :x => 1, :y => 2, :z => 4
puts s.z