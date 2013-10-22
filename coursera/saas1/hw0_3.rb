class BookInStock
	attr_accessor :isbn
	attr_accessor :price

	def initialize(_isbn, _price)
		raise ArgumentError, 'isbn should not be empty' if _isbn.empty?
		raise ArgumentError, 'price should be positive' if _price <= 0

		@isbn 	= _isbn
		@price 	= _price
	end

	def price_as_string
		price_array = []
		price_array[0] = price
		price_float = price_array.map{|price| "%.2f" % price}
		return "$" + price_float[0]
	end
end

# book = BookInStock.new('ISBN01', 11.22)
# puts book.price
# puts book.isbn

# book2 = BookInStock.new('isbn2', 11.22)
# puts 'book2:'
# puts book.price
# puts 'end'

book3 = BookInStock.new('isbn3', 11.8)
puts book3.price_as_string