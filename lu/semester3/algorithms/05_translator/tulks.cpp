// Andrejs Jurcenoks aj05044 DSuPII PD5
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/05_translator/tulks.cpp

Praktiskais darbs PD5
“Tulks”

Uzdevuma formulējums

Programmētājs Pēterītis nolēma izveidot sev vienkāršu tekstu tulkošanas sistēmu, ar kuru varētu aizstāt Google Translate servisu, kad nav pieejama pirmās nepieciešamības lieta - internets. Viņš bija pārliecināts, ka to izdarīt nav nemaz tik grūti. Eksperimenta nolūkos viņš nolēma veidot triviālu prototipu. Pamēģiniet arī Jūs izveidot vienkāršas tulkošanas sistēmas prototipu.

Jums ir pieejama vārdnīca ar vēlamo valodu vārdiem. Vārdnīca ir kopa ar vārdu pāriem, kur pirmais vārds ir valodā A, bet otrais vārds ir pirmā vārda tulkojums valodā B. Ir zināms, ka vārdnīcā visi vārdi valodā A ir unikāli, t.i. tie nesatur dublikātus. Arī vārdnīcas B vārdi ir unikāli. Tas nozīmē, ka vārda tulkojums no valodas A uz valodu B ir viennozīmīgs, un arī vārda tulkojums no valodas B uz valodu A ir viennozīmīgs. Vārdnīcā ir iekļauti tikai tādi vārdi, kas sastāv no latīņu alfabēta mazajiem un lielajiem burtiem, kā arī cipariem ({a..z,A..Z,0..9}).

Ir iespējams noteikt kāds būs tulkošanas virziens, vai no valodas A uz valodu B, vai arī no valodas B uz valodu A.

Tulkojamais teksts sastāv no vārdiem, kas atdalīti ar vienu vai vairākiem tukšumiem. Vārdus veido simboli no kopas {a..z,A..Z,0..9}. Vārdu garums nav lielāks par 20. Teksts var būt sadalīts pa vairākām rindām. Tulkošana notiek vārdu pa vārdam atbilstoši vārdnīcai un tulkošanas virzienam. Tulkojumā rindu dalījums netiek saglabāts, t.i. tulkojums jādrukā vienā rindā. Ja kāds tulkojamais vārds netiek atrasts vārdnīcā, tad tas netiek tulkots, bet tulkojumā tiek rakstīts netulkojamais vārds, kuram priekšā tiek pielikta jautājuma zīme ‘?’.

Vārdnīcā neviens vārds nav garāks par 20 simboliem. Vārdnīcā nav vairāk par 50’000 vārdu pāriem. Tulkojamais teksts var būt neierobežoti liels.

Aizliegts izmantot jau gatavas datu struktūras (piemēram, String) un algoritmus (piemēram, qsort() un strcmp()). Viss ir jānoprogrammē pašiem, izņemot faila lasīšanas un rakstīšanas funkcijas.

Ieejas dati ir korekti saskaņā ar ieejas datu formātu un dotajiem ierobežojumiem.



Failu vārdi

tulks.c vai tulks.cpp, vai tulks.pas - programmas tekstam
tulks.in - ieejas dati
tulks.out - izpildes rezultāts

Ieeja:
Ieejas fails satur 3 datu blokus: vārdnīcu, tulkošanas virzienu un tulkojamo tekstu.
Vārdnīca sastāv no vārdu pārīšiem formā
                        <Word_A> <Word_B>
<Word_A> ir vārds valodā A, bet <Word_B> ir pirmajam vārdam atbilstošais vārds valodā B. Katrs vārdu pāris ir savā rindā. Vārdnīcā ir vismaz viens vārdu pāris, bet ne vairāk kā 50’000 vārdu pāru.
Pēc vārdnīcas seko tulkošanas virziens, kas jaunā rindā tiek kodēts ar 3 simbolu palīdzību. Simbolu virkne ‘-->’ nozīmē, ka jātulko no valodas A uz valodu B. Simbolu virkne ‘<--’ nozīmē, ka jātulko no valodas B uz valodu A.
Pēc tulkošanas virziena seko tulkojamais teksts. Tulkojamais teksts var aizņemt daudzas rindas. Vārdi ir atdalīti ar vienu vai vairāk tukšumiem. Tulkojamais teksts satur vismaz vienu vārdu.

Izeja:
Rezultātu failam jāsatur tulkojamā teksta tulkojums, ja to tulko vārdu pa vārdam atbilstoši dotajai vārdnīcai un tulkošanas virzienam. Viss tulkojums tiek drukāts vienā rindā neatkarīgi no rindu daudzuma tulkojamajā tekstā. Vārdi tiek atdalīti ar tukšumu. Ja kādam tulkojamajam vārdam vārdnīcā nav dots tulkojums, tad jādrukā tulkojamais vārds, tam priekšā pieliekot jautājuma zīmi ‘?’.
Lai saprastu rezultāta iegūšanu, skatīt dotos publisko testpiemērus.

Piemērs:
Ieejas faila tulks.in saturs:

meitene girl
iet go
skola school
vakar yesterday
puika boy
palikt stay
istaba room
but be
skaists beautiful
sodien today
pudele bottle
un and
kaudze heap
-->
pudele piena bija viena jo blakus gluda siena skaista meitene iet pec siena ko puika vakar un sodien plaut un kaudze kraut

Izejas faila tulks.out saturs:

bottle ?piena ?bija ?viena ?jo ?blakus ?gluda ?siena ?skaista girl go ?pec ?siena ?ko boy yesterday and today ?plaut and heap ?kraut

