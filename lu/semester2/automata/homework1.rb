##################################################################################
# 1) Noprogrammēt automātu, kas akceptē valodu LA={v | v sākas ar 0 un beidzas ar 00} alfabētā Σ={0, 1}
# –Drīkst izmantot jebkādu programmēšanas valodu
# –Programmā jābūt funkcijai, kas saņem ievadā simbolu virkni (string) un atgriež jā vai nē (boolean)
# –Jāiesniedz tikai pirmkods

def automata1(word)
    print 'running for: ' + word

    zero_first  = false
    zero_penult = false
    zero_last   = false

    accepted = '0'

    i = 0

    # taking the first char separately
    if !word[i].nil?
        i++
        zero_first = (word[i] == accepted)
        zero_last = zero_first
    end

    # all next, till end of word, are processed in loop
    while !word[i].nil?
        i++
        zero_penult = zero_last
        zero_last = (word[i] == accepted)
    end

    return
        zero_first  &&
        zero_penult &&
        zero_last
end

def assert(actual, expected)
    if actual = expected
        puts ': succeeded'
    else
        puts ': failed'
    end
end

assert(automata1(''), false)
assert(automata1('0'), false)
assert(automata1('00'), true)
assert(automata1('010'), false)
assert(automata1('0100'), true)

##################################################################################
# 2) Neformāli aprakstīt vispārīgus principus, kā noprogrammēt patvaļīgu automātu.