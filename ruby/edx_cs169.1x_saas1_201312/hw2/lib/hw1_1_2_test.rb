def count_words(input)
# words = input.downcase.delete("^a-zA-Z0-9_").split (" ")
words = input.downcase.split (" ")
freq = Hash.new(0)
words.each {|x| freq[x] +=1}
return freq
end

print count_words('four four four')