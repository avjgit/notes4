// Andrejs Jurcenoks aj05044 DSuPII PD5
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/05_translator/tulks.cpp

#include <fstream>
// * Aizliegts izmantot jau gatavas datu struktūras (piemēram, String) un algoritmus (piemēram, qsort() un strcmp()).
int main() {

    FILE* in = fopen("tulks.in", "r");
    FILE* out = fopen("tulks.out", "w+");

// ################################# Ieeja:
// Ieejas fails satur 3 datu blokus: vārdnīcu, tulkošanas virzienu un tulkojamo tekstu.
// ============ Vārdnīca sastāv no vārdu pārīšiem formā <Word_A> <Word_B>
    char word_a[20];
    char word_b[20];
    fscanf(in, "%s", word_a);
    fprintf(out, "%s%s", word_a, " ");


// Vārdnīcā ir vismaz viens vārdu pāris, bet ne vairāk kā 50’000 vārdu pāru.
// Ir zināms, ka vārdnīcā visi vārdi valodā A ir unikāli, t.i. tie nesatur dublikātus. Arī vārdnīcas B vārdi ir unikāli.
// Tas nozīmē, ka vārda tulkojums no valodas A uz valodu B ir viennozīmīgs, un arī vārda tulkojums no valodas B uz valodu A ir viennozīmīgs.
// Vārdnīcā ir iekļauti tikai tādi vārdi, kas sastāv no latīņu alfabēta mazajiem un lielajiem burtiem, kā arī cipariem ({a..z,A..Z,0..9}).

    char a = 'a';
    int ai = a;
    char z = 'z';
    int zi = z;
    char aup = 'A';
    int aupi = aup;
    char c1 = '1';
    int c1i = c1;

    fprintf(stdout, "print test %i, %i, %i, %i", ai, zi, aupi, c1i);



// ============ Pēc vārdnīcas seko tulkošanas virziens, kas jaunā rindā tiek kodēts ar 3 simbolu palīdzību.
// Simbolu virkne ‘-->’ nozīmē, ka jātulko no valodas A uz valodu B.
// Simbolu virkne ‘<--’ nozīmē, ka jātulko no valodas B uz valodu A.
// ============ Pēc tulkošanas virziena seko tulkojamais teksts.
// Tulkojamais teksts var aizņemt daudzas rindas.
// Vārdi ir atdalīti ar vienu vai vairāk tukšumiem.
// Vārdus veido simboli no kopas {a..z,A..Z,0..9}.
// Tulkojamais teksts satur vismaz vienu vārdu.
// Tulkojamais teksts var būt neierobežoti liels.
// ################################# Izeja:
// Rezultātu failam jāsatur tulkojamā teksta tulkojums, ja to tulko vārdu pa vārdam atbilstoši dotajai vārdnīcai un tulkošanas virzienam.
// Viss tulkojums tiek drukāts vienā rindā neatkarīgi no rindu daudzuma tulkojamajā tekstā.
// Vārdi tiek atdalīti ar tukšumu.
// Ja kādam tulkojamajam vārdam vārdnīcā nav dots tulkojums, tad jādrukā tulkojamais vārds, tam priekšā pieliekot jautājuma zīmi ‘?’.
    fclose(in);
    fclose(out);
    return 0;
}