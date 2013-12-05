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

# print(buildCoder(4))

def applyCoder(text, coder):
    """
    Applies the coder to the text. Returns the encoded text.

    text: string
    coder: dict with mappings of characters to shifted characters
    returns: text after mapping coder chars to original text
    """
    cipher = coder
    s = ""
    for c in text:
        if c in cipher:
            s = s + cipher[c]
        else:
            s = s + c
    return s

# print(applyCoder("Hello, world!", buildCoder(3)))

def applyShift(text, shift):
    """
    Given a text, returns a new text Caesar shifted by the given shift
    offset. Lower case letters should remain lower case, upper case
    letters should remain upper case, and all other punctuation should
    stay as it is.

    text: string to apply the shift to
    shift: amount to shift the text (0 <= int < 26)
    returns: text after being shifted by specified amount.
    """
    return(applyCoder(text, buildCoder(shift)))

print(applyShift('This is a test.', 8))