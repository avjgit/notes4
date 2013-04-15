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
    char key_deactivate[KEY_SIZE];
    char key [KEY_SIZE];
    bool are_keys_equal;
    char value [KEY_SIZE];

    for (int i = 0; i < KEY_SIZE; i++)
    {
        key[i] = ' ';
    }

    for (int i = 0; i < KEY_SIZE; i++)
    {
        key_deactivate[i] = ' ';
    }

    int flag;
    int records_total = 0;
    int records_deactivated = 0;

    cout << "Enter key of records to deactivate: ";
    cin >> key_deactivate;

    fstream fin ("iofile.bin", ios::in | ios::out | ios::binary);

    fin.read (key, KEY_SIZE);
    fin.seekg(VALUE_SIZE, ios::cur);
    // fin.read (value, KEY_SIZE);

    while (fin)
    {
        records_total++;
        cout << "Checking entry  " << records_total << endl;

        // check if key is the one to deactivate
        are_keys_equal = true;
        for (int i = 0; i < KEY_SIZE; i++)
        {
            cout << "key " << i << " is " << key[i] << endl;
            cout << "key_deactivate " << i << " is " << key_deactivate[i] << endl;

            if (key[i] != key_deactivate[i])
            {
                are_keys_equal = false;
                break;
            }
        }

        cout << "out of loop" << endl;

        // if it is the key - then deactivate, else skip to next
        if (are_keys_equal)
        {
            cout << "writing" << endl;
            fin.write ((char*)&FLAG_INACTIVE, sizeof(int));
            records_deactivated++;
        }
        else
        {
            cout << "skipping" << endl;

            // fin.read ((char*)&flag, sizeof(int));
            fin.seekg(sizeof(int), ios::cur);
            cout << fin.tellg() << endl;
        }

        cout << "reading next" << endl;
        fin.read (key, KEY_SIZE);
        // fin.read (value, KEY_SIZE);
        fin.seekg(VALUE_SIZE, ios::cur);
    }
    cout << records_deactivated << " out of " << records_total << " deactivagted." << endl;
    fin.close ();
}

// (2) izdrukā faila esošās komponentes uz ekrāna
void print()
{
    char key [KEY_SIZE];
    char value [VALUE_SIZE];
    int flag;
    fstream fin ("iofile.bin", ios::in | ios::binary);
    cout << "-------------------" << endl;
    cout << "File content:" << endl;
    cout << "-------------------" << endl;
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

    for (int i = 0; i < KEY_SIZE; i++)
    {
        key[i] = ' ';
    }

    for (int i = 0; i < VALUE_SIZE; i++)
    {
        value[i] = ' ';
    }

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
        cout << endl;
        cout << "-------------------" << endl;
        cout << "Choose your action:" << endl;
        cout << "-------------------" << endl;
        cout << "Enter '" << menu_add               << "' to (a)dd new entry"               << endl;
        cout << "Enter '" << menu_print             << "' to (p)rint all entries"           << endl;
        cout << "Enter '" << menu_mark_inactive     << "' to (m)ark value inactive"         << endl;
        cout << "Enter '" << menu_remove_inactive   << "' to (r)emove all inactive values"  << endl;
        cout << "Enter '" << menu_quit              << "' to (q)uit"                        << endl;
        cout << "Your choice: ";
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
