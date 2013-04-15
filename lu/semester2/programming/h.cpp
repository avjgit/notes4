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
    const char menu_mark_inactive   = 'm';
    const char menu_print           = 'p';
    const char menu_remove_inactive = 'r';
    const char menu_add             = 'a';
    const char menu_exit            = 'x';

    const int KEY_SIZE      = 3; //30
    const int VALUE_SIZE    = 3; //30
    const int FLAG_SIZE     = 1;

    const int RECORD_SIZE   = KEY_SIZE + VALUE_SIZE + FLAG_SIZE;
    const int FLAG_ACTIVE   = 1;
    const int FLAG_INACTIVE = 0;

    char key    [KEY_SIZE];
    char value  [VALUE_SIZE];

    fstream iofile;

    iofile.open("iofile.bin", ios::out | ios::binary);

    cout << "enter key: ";
    cin >> key;
    iofile.write (key, KEY_SIZE);

    cout << "enter value: ";
    cin >> value;
    iofile.write (value, VALUE_SIZE);

    iofile.write ((char*)&FLAG_ACTIVE, sizeof(int));
    iofile.close ();

    fstream fin ("iofile.bin", ios::in);
    fin.read (key, KEY_SIZE);
    fin.read (value, VALUE_SIZE);
    fin.read ((char*)&FLAG_ACTIVE, sizeof(int));


    cout << key << endl;
    cout << value << endl;
    cout << FLAG_ACTIVE << endl;

    // while (fin)
    // {
    //     cout << i << endl;
    //     fin.read ((char*)&i, sizeof(int));
    // };

    fin.close ();

    cin >> key;
    return 0;
}
