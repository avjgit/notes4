class Car
	attr_accessor :model
	attr_accessor :price

	def initialize(_model, _price)
		@model = _model
		@price = _price
	end

end

vw = Car.new('Volkswagen', 1000)
bmw = Car.new('BMW', 10000)

if bmw > vw
	print 'costs more'
else
	print 'costs less'
end