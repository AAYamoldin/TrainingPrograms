say_hi = lambda {puts "Hi"}
say_bye = lambda{puts "bye"}
week = [say_hi,say_hi,say_hi,say_hi,say_hi,say_bye,say_bye]

week.each do |f|
  f.call
end