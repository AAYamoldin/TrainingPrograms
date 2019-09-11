class Artist
  attr_reader :artist, :albums
  def initialize artist
    @artist = artist
    @albums = []
  end
  def adding_album album
    @albums << album
  end
end

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
  attr_reader :nameofsong, :durationofsong
  def initialize name, duration
   @nameofsong = name
   @durationofsong = duration
  end
end

song1 = Song.new("Numb", 4)
song2 = Song.new("Faint", 5 )
song3 = Song.new("Как это было давно", 6)
song4 = Song.new("Провода", 8)
album1 = Album.new("Collision Cource")
album2 = Album.new("дома")
album3 = Album.new("meteora")
artist1 = Artist.new("Linkin Park")
artist2 = Artist.new("Guf")
album1.adding_song(song1)
album1.adding_song(song2)
album2.adding_song(song3)
album2.adding_song(song4)
artist1.adding_album(album1)
artist1.adding_album(album3)
artist2.adding_album(album2)
artists = []
artists << artist1
artists << artist2

# puts artists[0].artist
# puts artists[0].albums[0].nameofalbum
# puts artists[0].albums[0].songinalbum[0].nameofsong
# puts artists[0].albums[0].songinalbum[0].durationofsong

artists.each do |artist|
  print "\n Artist \"#{artist.artist}\" have"
  artist.albums.each do |album|
    print " \"#{album.nameofalbum}\" which contains "
    album.songinalbum.each do |song|
      print "\"#{song.nameofsong}\" with duration #{song.durationofsong}min "
    end
  end
end

