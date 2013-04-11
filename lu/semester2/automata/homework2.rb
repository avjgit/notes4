# TASK:
# 1)Uzbūvēt ε-avotu, kas akceptē, tos un tikai tos vārdus,
# kas pieder valodai L={w┤|  w satur abus fragmentus gulbis un nadals} alfabētā Σ=ASCII.
# 2)Determinizēt uzbūvēto avotu.
# 3)Noprogrammēt uzbūvēto automātu:
# –Drīkst izmantot jebkādu programmēšanas valodu
# –Nedrīkst izmantot jebkāda veida bibliotēkas, kas meklē tekstā, piemēram, regulārās izteiksmes.
# –Programmā jābūt funkcijai, kas saņem ievadā simbolu virkni (string) un atgriež sarakstu ar visām fragmenta gulbis beigu simbola atrašanās pozīcijām simbolu virknē.
# Jāiesniedz: ε-avots, determinēts automāts, pirmkods
# -----------------------------------------------------
# 1)Uzbūvēt ε-avotu, kas akceptē, tos un tikai tos vārdus,
# kas pieder valodai L={w┤|  w satur abus fragmentus gulbis un nadals} alfabētā Σ=ASCII.

==> (a)
        #virziens nr1: apaļa bultiņa, uz to pašu saakuma staavokli a - ne-gulbis un ne-nadals
        -Σ->(a)
        #virziens nr2: atrod "gulbis", tad vienalga ko (vai arī neko), tad "nadals", tad atkal - vienalga, ko
        -ɛ->(01)-g->(02)-u->(03)-l->(04)-b->(05)-i->(06)-s->(07)-Σ->(07)-ɛ->(08)-n->(09)-a->(10)-d->(11)-a->(12)-l->(13)-s->(14)-Σ->(14)
