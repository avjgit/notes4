import string
#
# Problem 1: Encryption
#
def buildCoder(shift):
    """
    Returns a dict that can apply a Caesar cipher to a letter.
    The cipher is defined by the shift value. Ignores non-letter characters
    like punctuation, numbers and spaces.

    shift: 0 <= int < 26
    returns: dict
    """
    d = {}

    chars = string.ascii_lowercase
    for c in chars:
        next_index = (chars.index(c) + shift) % len(chars)
        d[c] = chars[next_index];

    chars = string.ascii_uppercase
    for c in chars:
        next_index = (chars.index(c) + shift) % len(chars)
        d[c] = chars[next_index];
    return d

print(buildCoder(4))