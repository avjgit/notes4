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

    # pseudocode
    # take char (first)
    # if it is zero, proceed
        # save it as first, and also pre-last
    # take next
        # save it as last
        #
    print word[1]

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

if 'as'[1].nil?
    puts 'nothing here'
else
    puts 'ok, it was ' + 'as'[1]
end


if 'as'[2].nil?
    puts 'nothing here'
else
    puts 'ok, it was ' + 'as'[1]
end
##################################################################################
# 2) Neformāli aprakstīt vispārīgus principus, kā noprogrammēt patvaļīgu automātu.