def anagrams(words)
	words = words.split(" ")
	# print words[0].split("").sort.join
	# print words[0].chars.sort.join

	# words.each{|w|
		# w = w.split("").sort.join
		# w = w.chars.sort.join
	# }
	# print words
	a = words.group_by { |x| x.chars.sort }.values
	return a
end

puts anagrams("rats tars star foo")