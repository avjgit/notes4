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
01  00  02  0   0   0   0   0   0   0   0   01
02  00  0   03  0   0   0   0   0   0   0   02
03  00  0   0   04  0   0   0   0   0   0   03
04  00  0   0   0   05  0   0   0   0   0   04
05  00  0   0   0   0   06  0   0   0   0   05
06  00  0   0   0   0   0   07  0   0   0   06
07  07  07  07  07  07  07  07  09  07  07  08
08  07  07  07  07  07  07  07  09  07  07  08
09  07  07  07  07  07  07  07  07  10  07  09
10  07  07  07  07  07  07  07  07  07  11  10
11  07  07  07  07  07  07  07  07  12  07  11
12  07  07  07  13  07  07  07  07  07  07  12
13  07  07  07  07  07  07  14  07  07  07  13
14  14  14  14  14  14  14  14  14  14  14  14
15  00  0   0   0   0   0   0   16  0   0   15
16  00  0   0   0   0   0   0   0   17  0   16
17  00  0   0   0   0   0   0   0   0   18  17
18  00  0   0   0   0   0   0   0   19  0   18
19  00  0   0   20  0   0   0   0   0   0   19
20  00  0   0   0   0   0   21  0   0   0   20
21  21  23  21  21  21  21  21  21  21  21  22
22  21  23  21  21  21  21  21  21  21  21  22
23  21  21  24  21  21  21  21  21  21  21  23
24  21  21  21  25  21  21  21  21  21  21  24
25  21  21  21  21  26  21  21  21  21  21  25
26  21  21  21  21  21  27  21  21  21  21  26
27  21  21  21  21  21  21  28  21  21  21  27
28  28  28  28  28  28  28  28  28  28  28  28
