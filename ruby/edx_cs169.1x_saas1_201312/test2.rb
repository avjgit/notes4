class MyTest
	def print_this(input1)
		puts input1
	end
	def print_this(input1, input2)
		puts input1 + ' ' + input2
	end
end

m = MyTest.new()
m.print_this('blabla')
m.print_this('blabla', 'asdf')