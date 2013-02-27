##################################################################################
# 1) Noprogrammēt automātu, kas akceptē valodu LA={v | v sākas ar 0 un beidzas ar 00} alfabētā Σ={0, 1}
# –Drīkst izmantot jebkādu programmēšanas valodu
# –Programmā jābūt funkcijai, kas saņem ievadā simbolu virkni (string) un atgriež jā vai nē (boolean)
# –Jāiesniedz tikai pirmkods

# Kā izmantot programmu:
# Instalēt Ruby (http://www.editrocket.com/articles/ruby_windows.html)
# un no Windows comandrindas (CMD) tajā direktorijā, kur atrodas šis fails, palaist komandu "ruby homework1.rb".
# Tiks izpildīti testi (piem., assert(automata1(''), false)), kas atrodas failā.
# Var pievienot jebkurus papildus testus (piem., assert(automata1('0 vai sis vards tiks akceptets? 00'), true)).
# Piezīme: programmējot automātu, tika interpretēts, ka vārds '00' ir akceptējams (jo iepriekšpēdējāa vienlaikus ir pirmā)
# Darba versiju vēsture atrodama https://github.com/avjgit/notes4/blob/master/lu/semester2/automata/homework1.rb.

def automata1(word)
    print 'running for: ' + word

    zero_first  = false
    zero_penult = false
    zero_last   = false

    accepted = '0'

    if word[0] == accepted

        zero_first = true
        zero_last  = true

        i = 1
        while !word[i].nil?
            zero_penult = zero_last
            zero_last = (word[i] == accepted)
            i += 1
        end
    end

    return zero_first  &&
           zero_penult &&
           zero_last
end

def assert(actual, expected)
    puts actual == expected ? ': succeeded' : ': failed'
end

assert(automata1(''), false)
assert(automata1('0'), false)
assert(automata1('00'), true)
assert(automata1('010'), false)
assert(automata1('0100'), true)
assert(automata1('10001'), false)

##################################################################################
# 2) Neformāli aprakstīt vispārīgus principus, kā noprogrammēt patvaļīgu automātu.

# Jānoskaidro akceptors. Proti,
# - kādi ir visi iespējamie stāvokļi
# - kurš no tiem ir sākuma stāvoklis
# - kuri no tiem ir "laimīgu beigu" (akceptējošie) stāvokļi
# - kā var starp stāvokļiem pārvietoties (alfabēts un pārejas funkcija)
# Alfabēts tiek izmantots pārejas funkcijā - sastādot akcetora tabulu
# (proti, katram iespējamajam simbolam norādot automata nākamo stāvokli).