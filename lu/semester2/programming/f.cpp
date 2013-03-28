// task:
// Izveidot programmu valodā C++, kas apstrādā teksta failu secīgā režīmā.
// Dati no faila jānolasa pa vienam simbolam (nedrīkst nolasīt uzreiz visu failu vai veselu rindiņu).
// Nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
// F10. Doti divi faili f1 un f2.
// Failā f1 ir patvaļīgs teksts,
// failā f2 ir ne vairāk kā 40 vārdu pārīšu,
// kas atdalīti ar komatiem.
// Izdrukāt failā tekstu no ieejas faila f1,
// kurā visi vārdi, kas ir sastopami failā f2 kā pirmā komponente no pārīša,
// tiek aizstāti ar tam atbilstošo failā f2 norādīto vārdu.
// Drīkst uzskatīt, ka vārda garums failā nepārsniedz 40 simbolus.
// Par vārdu uzskatīt patvaļīgu simbolu virkni,
// kas atdalīta ar tukšumiem vai pieturas zīmēm
// (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme).

#include <iostream>
#include <fstream>
using namespace std;

bool is_end_of_word(char c)
{
    char separators[] = {' ', '.', ',', '(', ')', '!', '?'};
    int arrSize = sizeof(separators) / sizeof(char);
    for (int i = 0; i < arrSize; i++)
    {
        if (separators[i] == c)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // tests of is_end_of_word
    // if (is_end_of_word('a')) {cout << "nok";} else {cout << "ok";}
    // if (is_end_of_word(' ')) {cout << "ok";} else {cout << "nok";}
    // if (is_end_of_word('?')) {cout << "ok";} else {cout << "nok";}

    char c;        // character to read in
    char word[40]; // array to save a word read in
    fstream f1 ("f1");
    fstream f2 ("f2");

    c = f1.get();
    while (!f1.eof()) {
        cout << c;
        f2 << c;
        c = f1.get();
    }

    f1.close();
    f2.close();
    return 0;
}
