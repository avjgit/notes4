# Define a method sum which takes an array of integers as an argument
# and returns the sum of its elements. For an empty array it should return zero.
def sum (integers)
	# return integers.inject(0){|sum_, num| sum_ += num}
	sum_ = 0
	integers.each {|i| sum_ += i}
	return sum_
end

# testarray = [3, 6, 8]
# puts sum(testarray)

# testarray2 = []
# puts sum(testarray2)

# Define a method max_2_sum
# which takes an array of integers as an argument
# and returns the sum of its two largest elements.
# For an empty array it should return zero.
# For an array with just one element, it should return that element.
def max_2_sum(ints)
	return 0 if ints.empty?
	return ints[0] if ints.length == 1
	ints.sort!.reverse!
	return ints[0] + ints[1]
end

# ints = [6, 200, 4, 100]
# puts max_2_sum(ints)

# ints2 = []
# puts max_2_sum(ints2)

# ints3 = [3]
# puts max_2_sum(ints3)


#Define a method sum_to_n?
# which takes an array of integers
# and an additional integer, n, as arguments
# and returns true
# if any two elements in the array of integers sum to n.
# An empty array should sum to zero by definition.
def sum_to_n?(ints, n)
	# ints.each{|first|
	# 	ints.each{|second|
	# 		return true if first + second == n
	# 	}
	# }
	# return false
	if ints.empty?
		ints[0,1] = 0,0
		# return n == 0 ? true : false
	end

	combinations = ints.combination(2).to_a
	combinations.each{|c|
		return true if c[0] + c[1] == n
	}
	return false
end


# ints = [1, 2, 9, 5]
# ints = [1]
# ints = []

# if sum_to_n?(ints, 0)
# if sum_to_n?(ints, 9)
# 	print 'yeah, found'
# else
# 	print 'did not found'
# end