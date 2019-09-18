output = File.open("./filenew.txt","a")
output.write "something \n"
output.close
input = File.open("./test.txt", "r")
totalearn = 0
while (line = input.gets)
   puts line
  aa = line.split(",")
  totalearn = totalearn + aa[1].to_i
end
input.close
puts "total earn = #{totalearn}"
puts Dir.pwd
print Dir.entries "/home/alexander/Projects/"