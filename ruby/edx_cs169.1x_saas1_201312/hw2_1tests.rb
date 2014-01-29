def count_words(input)
	words = input.split(" ")
	words_counted = Hash.new()
	# words_counted['blabla'] = 1
	# print words_counted['blabla']
	words.each{|w|
		if words_counted.has_key?(w)
			words_counted[w] = words_counted[w]+1
		else
			words_counted[w] = 1
		end
	}
	words_counted
end

print count_words('this is this and that is that yes it is')