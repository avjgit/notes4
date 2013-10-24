# myvar = nil

# if myvar.nil?
# 	puts 'is empty'
# else
# 	puts 'is not empty'
# end

# myvar = 1

class MyClass
	attr_accessor :first
	def initialize
		@first = 'Kevin'
	end
end
m = MyClass.new()
puts 'start'
puts m.first
m.first = 'Arnold'
puts m.first
puts 'end'