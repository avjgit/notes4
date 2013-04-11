# Darba versiju vēsture atrodama https://github.com/avjgit/notes4/commits/master/lu/semester2/automata/homework2.rb
# -----------------------------------------------------
# 1)Uzbūvēt ε-avotu, kas akceptē, tos un tikai tos vārdus,
# kas pieder valodai L={w┤|  w satur abus fragmentus gulbis un nadals} alfabētā Σ=ASCII.
# ==> 00
#         #virziens nr1: apaļa bultiņa, uz to pašu saakuma staavokli 00 - ne-gulbis un ne-nadals
#         -Σ->(00)
#         #virziens nr2: atrod "gulbis", tad vienalga ko (vai arī neko), tad "nadals", tad atkal - vienalga, ko
#         -ɛ->(01)-g->(02)-u->(03)-l->(04)-b->(05)-i->(06)-s->(07)-Σ->(07)-ɛ->(08)-n->(09)-a->(10)-d->(11)-a->(12)-l->(13)-s->(14)-Σ->(14)
#         #virziens nr3: taapat, kaa virziens nr2, bet saakumaa "nadals", un tad "gulbis"
#         -ɛ->(15)-n->(16)-a->(17)-d->(18)-a->(19)-l->(20)-s->(21)-Σ->(21)-ɛ->(22)-g->(23)-u->(24)-l->(25)-b->(26)-i->(27)-s->(28)-Σ->(28)
# -----------------------------------------------------
# 2)Determinizēt uzbūvēto avotu.
#       Σ   G   U   L   B   I   S   N   A   D   ɛ
#   0   0   2   0   0   0   0   0   0   0   0   (1,15)
#   1   0   2   0   0   0   0   0   0   0   0   1
#   2   0   0   3   0   0   0   0   0   0   0   2
#   3   0   0   0   4   0   0   0   0   0   0   3
#   4   0   0   0   0   5   0   0   0   0   0   4
#   5   0   0   0   0   0   6   0   0   0   0   5
#   6   0   0   0   0   0   0   7   0   0   0   6
#   7   7   7   7   7   7   7   7   9   7   7   8
#   8   7   7   7   7   7   7   7   9   7   7   8
#   9   7   7   7   7   7   7   7   7   10  7   9
#   10  7   7   7   7   7   7   7   7   7   11  10
#   11  7   7   7   7   7   7   7   7   12  7   11
#   12  7   7   7   13  7   7   7   7   7   7   12
#   13  7   7   7   7   7   7   14  7   7   7   13
#   14  14  14  14  14  14  14  14  14  14  14  14
#   15  0   0   0   0   0   0   0   16  0   0   15
#   16  0   0   0   0   0   0   0   0   17  0   16
#   17  0   0   0   0   0   0   0   0   0   18  17
#   18  0   0   0   0   0   0   0   0   19  0   18
#   19  0   0   0   20  0   0   0   0   0   0   19
#   20  0   0   0   0   0   0   21  0   0   0   20
#   21  21  23  21  21  21  21  21  21  21  21  22
#   22  21  23  21  21  21  21  21  21  21  21  22
#   23  21  21  24  21  21  21  21  21  21  21  23
#   24  21  21  21  25  21  21  21  21  21  21  24
#   25  21  21  21  21  26  21  21  21  21  21  25
#   26  21  21  21  21  21  27  21  21  21  21  26
#   27  21  21  21  21  21  21  28  21  21  21  27
#   28  28  28  28  28  28  28  28  28  28  28  28
# -----------------------------------------------------
# 3)Noprogrammēt uzbūvēto automātu:
# –Drīkst izmantot jebkādu programmēšanas valodu
# –Nedrīkst izmantot jebkāda veida bibliotēkas, kas meklē tekstā, piemēram, regulārās izteiksmes.
# –Programmā jābūt funkcijai, kas saņem ievadā simbolu virkni (string) un atgriež sarakstu ar visām fragmenta gulbis beigu simbola atrašanās pozīcijām simbolu virknē.
def automata2(word)
    print 'running for: ' + word

    has_gulbis = false
    i = 0
    while !word[i].nil?
        if(word[i]   == 'g' &&
           word[i+1] == 'u' &&
           word[i+2] == 'l' &&
           word[i+3] == 'b' &&
           word[i+4] == 'i' &&
           word[i+5] == 's'
        )
            has_gulbis = true
        end
        i += 1
    end

    has_nadals  = false
    i = 0
    while !word[i].nil?
        if(word[i]   == 'n' &&
           word[i+1] == 'a' &&
           word[i+2] == 'd' &&
           word[i+3] == 'a' &&
           word[i+4] == 'l' &&
           word[i+5] == 's'
        )
            has_nadals = true
        end
        i += 1
    end

    return has_gulbis && has_nadals
end

def gulbis_positions(word)
    print 'running for: ' + word
    positions = []
    i = 0
    while !word[i].nil?
        if(word[i]   == 'g' &&
           word[i+1] == 'u' &&
           word[i+2] == 'l' &&
           word[i+3] == 'b' &&
           word[i+4] == 'i' &&
           word[i+5] == 's'
        )
            positions << i+6
        end
        i += 1
    end

    return positions
end
def assert(actual, expected)
    puts actual == expected ? ': succeeded' : ': failed'
end

assert(automata2('gulbisnadals'), true)
assert(automata2('_gulbis_nadals_'), true)

assert(automata2('nadalsgulbis'), true)
assert(automata2('_nadals_gulbis_'), true)

assert(automata2('gulbis'), false)
assert(automata2('nadals'), false)

assert(gulbis_positions('gulbis'), [6])
assert(gulbis_positions('_gulbis_gulbis_gulbis_'), [7, 14, 21])