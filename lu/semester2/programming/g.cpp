
// Izveidot programmu valodā C++, kas ļauj izveidot vienvirziena saistīto sarakstu (izmantojot dinamiskās datu struktūras), kurā glabājas noteikta tipa vērtības. Jābūt  paredzētai iespējai sarakstu papildināt ar jaunu elementu (pielikt elementu saraksta galā), izdrukāt sarakstu, iznīcināt sarakstu. Bez tam jāuzraksta funkcija, kura aprakstīta zemāk. Iznīcinot saraksta elementus, korekti jāatbrīvo izdalītā atmiņa. Galvenajā programmā:
//   a) jābūt iespējai ievadīt saraksta elementus (izveidot patvaļīgu sarakstu),
//   b) jāpielieto uzrakstītā funkcija sarakstam,
//   c) jāizdrukā saraksts pēc funkcijas darbības.
//   d) beigās jāiznīcina saraksts (lietojot delete).
// G9. Uzrakstīt funkciju, kas pārvieto saraksta n-to elementu uz saraksta beigām. Darbība jāveic, pārkabinot saites, nevis pārrakstot elementu vērtības.
#include <iostream>
using namespace std;

int main()
{
    struct element
    {
        string content;
        element* next;
    };

    element* first      = NULL;
    element* last       = NULL;
    element* current    = NULL;
    string buffer;

    const char menu_add    = 'a';
    const char menu_print  = 'p';
    const char menu_quit   = 'q';
          char menu_chosen = ' ';

    while (menu_chosen != menu_quit)
    {
        cout << endl;
        cout << "-------------------" << endl;
        cout << "Choose your action:" << endl;
        cout << "-------------------" << endl;
        cout << "Enter '" << menu_add               << "' to (a)dd new entry"               << endl;
        cout << "Enter '" << menu_print             << "' to (p)rint all entries"           << endl;
        cout << "Enter '" << menu_quit              << "' to (q)uit"                        << endl;
        cout << "Your choice: ";
        cin >> menu_chosen;

        switch (menu_chosen) {
            case menu_add:
                current = new element;
                cout << "Add list item: ";
                cin >> buffer;
                current->content = buffer;
                current->next = NULL;

                if (first == NULL)
                {
                    first = current;
                    last = current;
                }
                else
                {
                    last->next = current;
                    last = last->next;
                }

                break;
            case menu_print:
                cout << "List content: " << endl;
                for(current = first; current != NULL; current = current->next)
                {
                    cout << "- " << current->content << endl;
                }
                break;
            case menu_quit:
                break;
            default:
                cout << "You have entered unrecognisable value." << endl;
          }
    }

    // free memory
    current = first;
    while (current != NULL)
    {
        first = first->next;
        delete current;
        current = first;
    }

    return 0;
}
