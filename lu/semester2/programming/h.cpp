// H6. Uzrakstīt programmu, kas ļauj izveidot un labot bināru failu,
// kura ieraksta struktūra ir sekojoša:
// vārds – atslēga (30 simboli),
// vārds – vērtība (30 simboli),
// ieraksta statuss (0 vai 1).
// Programmai katrs jauns ieraksts jāieliek faila beigās. Jāparedz iespēja
// (1) izmest faila komponenti (loģiski atzīmējot kā izmestu),
// (2) izdrukāt faila esošās komponentes uz ekrāna,
// (3) izmest loģiski izmestas komponentes fiziski.

#include <iostream>
#include <fstream>
using namespace std;

// (1) izmet faila komponenti (loģiski atzīmējot kā izmestu)
void mark_inactive()
{

}

// (2) izdrukā faila esošās komponentes uz ekrāna
void print()
{

}

// (3) izmet loģiski izmestas komponentes fiziski
void remove_inactive()
{

}

void add()
{

}

int main()
{
    const char menu_add             = 'a';
    const char menu_print           = 'p';
    const char menu_mark_inactive   = 'm';
    const char menu_remove_inactive = 'r';
    const char menu_quit            = 'q';

    char menu_chosen = ' ';

    while (menu_chosen != menu_quit)
    {
        cout << "Choose your action:" << endl;
        cout << "-------------------" << endl;
        cout << "Enter '" << menu_add               << "' to (a)dd new entry"               << endl;
        cout << "Enter '" << menu_print             << "' to (p)rint all entries"           << endl;
        cout << "Enter '" << menu_mark_inactive     << "' to (m)ark value inactive"         << endl;
        cout << "Enter '" << menu_remove_inactive   << "' to (r)emove all inactive values"  << endl;
        cout << "Enter '" << menu_quit              << "' to (q)uit"                        << endl;

        cin >> menu_chosen;

        switch (menu_chosen) {
            case menu_add:
                add();
                break;
            case menu_print:
                print();
                break;
            case menu_mark_inactive:
                mark_inactive();
                break;
            case menu_remove_inactive:
                remove_inactive();
                break;
            case menu_quit:
                break;
            default:
                cout << "You have entered unrecognisable value." << endl;
          }
    }


    // const int KEY_SIZE      = 3; //30
    // const int VALUE_SIZE    = 3; //30
    // const int FLAG_SIZE     = 1;

    // const int FLAG_ACTIVE   = 1;
    // const int FLAG_INACTIVE = 0;

    // char key    [KEY_SIZE];
    // char value  [VALUE_SIZE];

    // fstream iofile;

    // iofile.open("iofile.bin", ios::out | ios::app | ios::binary);

    // cout << "enter key: ";
    // cin >> key;
    // iofile.write (key, KEY_SIZE);

    // cout << "enter value: ";
    // cin >> value;
    // iofile.write (value, VALUE_SIZE);

    // iofile.write ((char*)&FLAG_ACTIVE, sizeof(int));
    // iofile.close ();

    // fstream fin ("iofile.bin", ios::in);
    // fin.read (key, KEY_SIZE);
    // fin.read (value, VALUE_SIZE);
    // fin.read ((char*)&FLAG_ACTIVE, sizeof(int));

    // cout << key << endl;
    // cout << value << endl;
    // cout << FLAG_ACTIVE << endl;

    // fin.close ();

    // cin >> key;

    return 0;
}
