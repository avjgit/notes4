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

int main()
{
    char c;
    fstream f1 ("f1");
    fstream f2 ("f2");

    c = f1.get();
    while (!f1.eof()) {
        cout << c;
        c = f1.get();
    }




    f1.close();
    f2.close();
    return 0;
}
