@hh = {}
def add_person name, age
  @hh[name] = age
end

def show_hash
  @hh.each do |key, values|
    puts "имя #{key} с возрастом #{values}"
  end
end

while 2 + 2 == 4
  print "введите имя человека (Enter для выхода): "
  answer = gets.strip.capitalize
  if answer == ""
    show_hash
    break
  end
  print "введите возраст человека "
  age = gets.to_i
  add_person answer, age
end