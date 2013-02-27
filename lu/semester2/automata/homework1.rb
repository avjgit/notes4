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
        zero_first = (word[i] == accepted)
        zero_last = zero_first
        i += 1
    end

    if zero_first
        p 'hey, first is 0'
    else
        p 'no, it is not'
    end

    # all next, till end of word, are processed in loop
    while !word[i].nil?
        zero_penult = zero_last
        zero_last = (word[i] == accepted)
        i += 1
    end

    if zero_last
        p 'hey, last is 0 too'
    else
        p 'no, it is not'
    end

    if zero_penult
        p 'hey, and penult??'
    else
        p 'no, it is not'
    end

    return
        zero_first  &&
        zero_penult &&
        zero_last
end

def assert(actual, expected)
    if actual
        puts ' actual true'
    else
        puts ' actual false'
    end
    if expected
        puts ' expected true'
    else
        puts ' expected false'
    end

    if actual === expected
        puts ': succeeded'
    else
        puts ': failed'
    end
end

assert(automata1(''), false)
# assert(automata1('0'), false)
# assert(automata1('00'), true)
# assert(automata1('010'), false)
# assert(automata1('0100'), true)
# automata1('')
# automata1('1')
# automata1('0')
if true == true
    p 'bool comparison works'
else
    p 'no it does not'
end
##################################################################################
# 2) Neformāli aprakstīt vispārīgus principus, kā noprogrammēt patvaļīgu automātu.