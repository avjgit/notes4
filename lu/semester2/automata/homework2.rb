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
# ==> 00
#         #virziens nr1: apaļa bultiņa, uz to pašu saakuma staavokli a - ne-gulbis un ne-nadals
#         -Σ->(00)
#         #virziens nr2: atrod "gulbis", tad vienalga ko (vai arī neko), tad "nadals", tad atkal - vienalga, ko
#         -ɛ->(01)-g->(02)-u->(03)-l->(04)-b->(05)-i->(06)-s->(07)-Σ->(07)-ɛ->(08)-n->(09)-a->(10)-d->(11)-a->(12)-l->(13)-s->(14)-Σ->(14)
#         #virziens nr3: taapat, kaa virziens nr2, bet saakumaa "gulbis", un tad "nadals"
#         -ɛ->(15)-n->(16)-a->(17)-d->(18)-a->(19)-l->(20)-s->(21)-Σ->(21)-ɛ->(22)-g->(23)-u->(24)-l->(25)-b->(26)-i->(27)-s->(28)-Σ->(28)
# -----------------------------------------------------
# 2)Determinizēt uzbūvēto avotu.
    Σ   G   U   L   B   I   S   N   A   D   ɛ
00  00  02  00  00  00  00  00  00  00  00  (01,15)
01  00  02  X   X   X   X   X   X   X   X   01
02  00  X   03  X   X   X   X   X   X   X   02
03  00  X   X   04  X   X   X   X   X   X   03
04  00  X   X   X   05  X   X   X   X   X   04
05  00  X   X   X   X   06  X   X   X   X   05
06  00  X   X   X   X   X   07  X   X   X   06
07  07  X   X   X   X   X   X   09  X   X   08
08  00  X   X   X   X   X   X   09  X   X   08
09  00  X   X   X   X   X   X   X   10  X   09
10  00  X   X   X   X   X   X   X   X   11  10
11  00  X   X   X   X   X   X   X   12  X   11
12  00  X   X   13  X   X   X   X   X   X   12
13  00  X   X   X   X   X   14  X   X   X   13
14  14  X   X   X   X   X   X   X   X   X   14
15  00  X   X   X   X   X   X   16  X   X   15
16  00  X   X   X   X   X   X   X   17  X   16
17  00  X   X   X   X   X   X   X   X   18  17
18  00  X   X   X   X   X   X   X   19  X   18
19  00  X   X   20  X   X   X   X   X   X   19
20  00  X   X   X   X   X   21  X   X   X   20
21  21  23  X   X   X   X   X   X   X   X   22
22  00  23  X   X   X   X   X   X   X   X   22
23  00  X   24  X   X   X   X   X   X   X   23
24  00  X   X   25  X   X   X   X   X   X   24
25  00  X   X   X   26  X   X   X   X   X   25
26  00  X   X   X   X   27  X   X   X   X   26
27  00  X   X   X   X   X   28  X   X   X   27
28  28  X   X   X   X   X   X   X   X   X   28
