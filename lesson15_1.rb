class Airport
  attr_reader :name
  attr_reader :planes
  def initialize name
    @name = name
    @planes = []
  end
  def add_plane plane
    @planes << plane
  end
end

class Plane
  attr_reader :model
  def initialize model
    @model = model
  end
end

class Country
  attr_reader :nameof, :airportsof
  def initialize nameof
    @nameof = nameof
    @airportsof = []
  end
  def add_airport airportname
    @airportsof << airportname
  end
 end
plane1 = Plane.new("Airbus A-320")
plane2 = Plane.new("Boeing 777")
plane3 = Plane.new("Tochno upadet")
plane4 = Plane.new("LOLKEK")
airport1 = Airport.new("Domodedovo")
airport2 = Airport.new("Lohovo")
country1 = Country.new("Russia")
country2 = Country.new("Kekovo")
country1.add_airport(airport1)
country2.add_airport(airport2)
airport1.add_plane(plane1)
airport1.add_plane(plane2)
airport1.add_plane(plane3)
airport2.add_plane(plane1)
airport2.add_plane(plane3)
airport2.add_plane(plane4)
contries = []
contries << country1
contries << country2

contries.each do |country|
  print "\n In #{country.nameof} находится "
  country.airportsof.each do |airports|
  print " #{airports.name}"
    airports.planes.each do |planes|
      print " с #{planes.model}"
    end
    end
end
