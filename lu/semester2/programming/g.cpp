
// Izveidot programmu valodā C++, kas ļauj izveidot vienvirziena saistīto sarakstu (izmantojot dinamiskās datu struktūras), kurā glabājas noteikta tipa vērtības. Jābūt  paredzētai iespējai sarakstu papildināt ar jaunu elementu (pielikt elementu saraksta galā), izdrukāt sarakstu, iznīcināt sarakstu. Bez tam jāuzraksta funkcija, kura aprakstīta zemāk. Iznīcinot saraksta elementus, korekti jāatbrīvo izdalītā atmiņa. Galvenajā programmā:
//   a) jābūt iespējai ievadīt saraksta elementus (izveidot patvaļīgu sarakstu),
//   b) jāpielieto uzrakstītā funkcija sarakstam,
//   c) jāizdrukā saraksts pēc funkcijas darbības.
//   d) beigās jāiznīcina saraksts (lietojot delete).
// G9. Uzrakstīt funkciju, kas pārvieto saraksta n-to elementu uz saraksta beigām.
// Darbība jāveic, pārkabinot saites, nevis pārrakstot elementu vērtības.
#include <iostream>
using namespace std;

struct element
{
    string content;
    element* next;
};

// element* first      = NULL;
// element* last       = NULL;
// element* current    = NULL;

void move(element* &first, element* &last, int nth)
{
    if (nth == 1)
    {
        last-> next = first;
        last        = first;
        first       = first->next;
        cout << "hey, first is now " << first->content << endl;
        last->next = NULL;
    }
    else
    {
        element* before     = NULL;
        element* current    = NULL;
        element* after      = NULL;

        int movable = nth;
        bool end_of_list = false;

        before  = first;
        current = first;
        after   = first->next;

        for(int i = 1; i < movable; i++)
        {
            before = current;
            current = after;

            if (current == NULL)
            {
                cout << "Element number is out of list; move is not possible." << endl;
                end_of_list = true;
                break;
            }

            after = current->next;

        }

        if (!end_of_list)
        {
            // change link before straight to after (skip "current")
            if (after != NULL)
            {
                before->next = after;
            }

            // if 1st?
            if (movable == 1)
            {
                first = current->next;
                cout << "first is now " << first->content;
            }

            last->next = current;
            last = last->next;

            current->next = NULL;
        }
    }
}

int main()
{
    element* first      = NULL;
    element* last       = NULL;
    element* current    = NULL;

    string buffer;

    const char menu_add    = 'a';
    const char menu_print  = 'p';
    const char menu_move   = 'm';
    const char menu_quit   = 'q';
          char menu_chosen = ' ';
    int movable;

    while (menu_chosen != menu_quit)
    {
        cout << endl;
        cout << "-------------------" << endl;
        cout << "Choose your action:" << endl;
        cout << "-------------------" << endl;
        cout << "Enter '" << menu_add               << "' to (a)dd new entry"               << endl;
        cout << "Enter '" << menu_print             << "' to (p)rint all entries"           << endl;
        cout << "Enter '" << menu_move              << "' to (m)ove entry to the end"       << endl;
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

                // cout << "first is now " << first->content;
                // cout << "last is " << last->content;


                for(current = first; current != NULL; current = current->next)
                {
                    cout << "- " << current->content << endl;
                }
                break;
            case menu_move:
                cout << "Which list item to move: ";
                cin >> movable;
                move(first, last, movable);
                cout << "after move, " << endl;
                cout << "first is now " << first->content;
                cout << "last is " << last->content;
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

// testa plans:

// tests 1
// 1) izveidot sarakstu ar elementiem "Adisabeba", "Berlin", "Cairo"
// 2) izdrukat sarakstu uz ekrana, parliecinoties, ka tas ir izveidots
// 3) izsaukt MOVE funkciju, parvietojot 2.elementu uz beigam
// 4) izdrukat sarakstu uz ekrana, parliecinoties, ka tas tagad ir "Adisabeba", "Cairo", "Berlin"


// tests 2
// 1) izveidot sarakstu ar elementiem "Adisabeba", "Berlin", "Cairo"
// 2) izdrukat sarakstu uz ekrana, parliecinoties, ka tas ir izveidots
// 3) izsaukt MOVE funkciju, meginot parvietot 15.elementu uz beigam
// 4) parliecinaties, ka tiek pazinota programmas kluda
// 5) parliecinaties, ka saraksts tika saglabats
