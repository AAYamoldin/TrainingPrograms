
class LineAnalyzer
  attr_reader :highest_wf_count, :highest_wf_words, :content, :line_number
  def initialize(line, line_num)
  @content = line
    @line_number = line_num
    self.calculate_word_frequency(line)
  end
def calculate_word_frequency(line)
  word_frequency = Hash.new(0)
  line.split.each do |word|
    word_frequency[word.downcase] += 1
  end
  @highest_wf_count = word_frequency.values.max
  @highest_wf_words = word_frequency.select {|key,value| value == word_frequency.values.max}.keys
end
end

class Solution
  attr_reader :analyzers, :highest_count_across_lines, :highest_count_words_across_lines, :highest_count_across_lines
 def initialize
  @analyzers = []
  @highest_count_words_across_lines = []

  end
  def analyze_file
    text = File.open("./test.txt", "r")
    text.each_line do |line|
    @analyzers << line
    end
  end


  def calculate_line_with_highest_frequency
    @arr = {}
    @analyzers.each_with_index do |line, index|
     lll = LineAnalyzer.new(line,index)
      @arr[lll.highest_wf_words] = lll.highest_wf_count#кол-во встречаний
    end
    @highest_count_across_lines = @arr.values.max#4
    @arr.values.each_with_index do |key_val, i|
      # puts "#{key_val} with index #{i}"
      @highest_count_words_across_lines  << i+1 if key_val == @highest_count_across_lines
    end
end

def print_highest_word_frequency_across_lines
  puts "The following words have the highest word frequency per line:"
  0.upto(@highest_count_words_across_lines.size-1) do |i|
    puts "#{@arr.select{|k,v| v == @highest_count_across_lines}.keys[i]} (appears in line #{@highest_count_words_across_lines[i]}!)"
  end
end
end
