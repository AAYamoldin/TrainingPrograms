class Album
  attr_reader :nameofalbum, :songinalbum
  def initialize name
    @nameofalbum = name
    @songinalbum = []
  end
  def adding_song song
    @songinalbum << song
  end
end

class Song
  attr_accessor :nameofsong, :durationofsong
  def initialize name, duration
    @nameofsong = name
    @durationofsong = duration
  end
end
song1 = Song.new("Numb", 4)
song2 = Song.new("Faint", 5 )
song3 = Song.new("Как это было давно", 6)
song4 = Song.new("Провода", 8)
album1 = Album.new("Linkin Park -Collision Cource")
album2 = Album.new("Guf - дома")
album1.adding_song(song1)
album1.adding_song(song2)
album2.adding_song(song3)
album2.adding_song(song4)
album = []
album << album1
album << album2

puts album1.songinalbum[0].nameofsong
# album.each do |album|
#   print "\n В альбоме #{album.nameofalbum} "
#   album.songinalbum.each do |song|
#     print "\n #{song.nameofsong} with duration #{song.durationofsong}"
#   end
# end

