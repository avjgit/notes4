##################################################################################
# 1) Noprogrammēt automātu, kas akceptē valodu LA={v | v sākas ar 0 un beidzas ar 00} alfabētā Σ={0, 1}
# –Drīkst izmantot jebkādu programmēšanas valodu
# –Programmā jābūt funkcijai, kas saņem ievadā simbolu virkni (string) un atgriež jā vai nē (boolean)
# –Jāiesniedz tikai pirmkods

def automata1(word)
    print 'running for: ' + word

    first_zero = true
    last1_zero = true
    last2_zero = true

    return
        first_zero &&
        last1_zero &&
        last2_zero
end

def assert(actual, expected)
    if actual = expected
        puts ': succeeded'
    else
        puts ': failed'
    end
end

assert(automata1('0'), false)
assert(automata1('00'), true)

##################################################################################
# 2) Neformāli aprakstīt vispārīgus principus, kā noprogrammēt patvaļīgu automātu.