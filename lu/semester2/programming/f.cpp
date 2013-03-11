// Izveidot programmu valodā C++, kas apstrādā teksta failu secīgā režīmā. Dati no faila jānolasa pa vienam simbolam (nedrīkst nolasīt uzreiz visu failu vai veselu rindiņu). Nedrīkst dublēt visa faila saturu operatīvajā atmiņā. Sīkākas prasības sk. Laboratorijas darbu noteikumos.
// F10. Doti divi faili f1 un f2. Failā f1 ir patvaļīgs teksts, failā f2 ir ne vairāk kā 40 vārdu pārīšu, kas atdalīti ar komatiem. Izdrukāt failā tekstu no ieejas faila f1, kurā visi vārdi, kas ir sastopami failā f2 kā pirmā komponente no pārīša, tiek aizstāti ar tam atbilstošo failā f2 norādīto vārdu. Drīkst uzskatīt, ka vārda garums failā nepārsniedz 40 simbolus. Par vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem vai pieturas zīmēm (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme).
// ========================================================
#include <stdio.h>
#include <fstream>
#include <iostream>

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
    // if (is_end_of_word(' ')) {cout << "ok";}  else {cout << "nok";}
    // if (is_end_of_word('?')) {cout << "ok";}  else {cout << "nok";}
    // end of tests of is_end_of_word

    char c;
    char word[40];
    ifstream inFile;
    ofstream outFile;
    inFile.open("f1");
    if(!inFile) return 1;
    outFile.open("f2");

    inFile >> c;

    while (!inFile.eof())
    {
        // cout << c;
        // inFile >> c;
        outFile << c;
        c = inFile.get();
    }
    // for (int i=0; i<150;i++)
    // {
    //     inFile >> c;
    //     cout << c;
    // }

    inFile.close();
    outFile.close();
    return 0;
}