class Strategy < String
	def <=>
		if self == 'S' and
	end
end

s = Strategy.new('S')
r = Strategy.new('R')

if r > s
	puts 'works'
else
	puts 'not'
end