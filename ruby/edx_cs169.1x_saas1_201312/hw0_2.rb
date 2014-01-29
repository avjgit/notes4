# Define a method hello(name)
# that takes a string representing a name
# and returns the string "Hello, " concatenated with the name.
def hello(name)
	return 'Hello, ' + name
end

# puts hello('everyone')

# Define a method starts_with_consonant?(s)
# that takes a string
# and returns true if it starts with a consonant
# and false otherwise.
# (For our purposes, a consonant is any letter other than A, E, I, O, U.)
# NOTE: be sure it works for both upper and lower case and for nonletters!
def starts_with_consonant?(s)
	# nonconsonants = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
	# nonconsonants_lowercase = nonconsonants.map{|char| char.downcase}
	# return 	!nonconsonants.include?(s[0])
	# return !s[0].match(/[AEIOUaeiou][[:punct:]]/)
	return false if s.empty?
	return s[0].match(/[AEIOUaeiou[:punct:][:digit:]]/) ? false : true
	# return s[0].match(/[[AEIOUaeiou]&&[a-z][A-Z]]/) ? false : true
	# return false if s[0].match(/[AEIOUaeiou[:punct:]]/)
	# return true
end

# puts starts_with_consonant?('Ksdf')
# puts starts_with_consonant?('osdf')
# puts starts_with_consonant?('!')
# puts starts_with_consonant?('.')
# puts starts_with_consonant?('k')
# puts starts_with_consonant?('')
# puts starts_with_consonant?('3')
# puts 'end of tests'

#Define a method binary_multiple_of_4?(s)
# that takes a string
# and returns true if the string represents a binary number that is a multiple of 4.
# NOTE: be sure it returns false if
# the string is not a valid binary number!
def binary_multiple_of_4?(s)
	s.split('').each{|i|
		return false if not i.match(/[10]/)
	}
	# return s[-1] == '0' && s[-2] == '0'
	return s[-2..-1] == '00'
end

if binary_multiple_of_4?('100')
	print 'yes'
else
	print 'no'
end
