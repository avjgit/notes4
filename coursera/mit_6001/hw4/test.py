s = 'azcbobobegghakl'

# Number of vowels: 5
# Paste your code into this box
VOWELS = 'aeiou'
vowels_counted = 0
for i in s:
    if i in VOWELS:
        vowels_counted += 1

print('Number of vowels: ' + str(vowels_counted))
