require 'fileutils'
file = File.open("./test.txt", "r")
tmpfile = File.open("./test1.txt","w")
counter = 0
totalearn = 0
file.each do |line|
  tmpfile << line
  if line.strip == "March, 30"
    tmpfile << "April, 100 \n"
  end
  # puts "месяц #{line.strip}, индекс #{counter}"
end
tmpfile.close
file.close
FileUtils.mv './test1.txt','./test.txt'

file = File.open("./test.txt", "r")
while (line = file.gets)
  totalearn = line.split(",")[1].to_i + totalearn
  counter +=1
  if counter == 6
    break
  end
end
puts totalearn