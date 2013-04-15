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

const int KEY_SIZE      = 30;
const int VALUE_SIZE    = 30;
const int FLAG_SIZE     = 1;
const int RECORD_SIZE   = KEY_SIZE + VALUE_SIZE + FLAG_SIZE;
const int FLAG_ACTIVE   = 1;
const int FLAG_INACTIVE = 0;

// (1) izmet faila komponenti (loģiski atzīmējot kā izmestu)
void mark_inactive()
{

}

// (2) izdrukā faila esošās komponentes uz ekrāna
void print()
{
    char key [KEY_SIZE];
    char value [VALUE_SIZE];
    int flag;
    fstream fin ("iofile.bin", ios::in | ios::binary);

    fin.read (key, KEY_SIZE);
    fin.read (value, VALUE_SIZE);
    fin.read ((char*)&flag, sizeof(int));
    while (fin)
    {
        cout << key <<": " << value << " " << flag << endl;

        fin.read (key, KEY_SIZE);
        fin.read (value, VALUE_SIZE);
        fin.read ((char*)&flag, sizeof(int));
    }
    fin.close ();
}

// (3) izmet loģiski izmestas komponentes fiziski
void remove_inactive()
{

}

void add()
{
    char key    [KEY_SIZE];
    char value  [VALUE_SIZE];
    int flag;
    fstream iofile;
    iofile.open("iofile.bin", ios::out | ios::app | ios::binary);

    cout << "Enter the key: ";
    cin >> key;
    iofile.write (key, KEY_SIZE);

    cout << "Enter the value: ";
    cin >> value;
    iofile.write (value, VALUE_SIZE);

    cout << "Enter the activity flag (1 or 0): ";
    cin >> flag;
    iofile.write ((char*)&flag, sizeof(int));

    iofile.close ();
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
    return 0;
}
