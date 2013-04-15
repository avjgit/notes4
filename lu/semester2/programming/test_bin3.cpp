    // int i;
    // fstream fin ("integers.bin", ios::in);
    // fin.read ((char*)&i, sizeof(int));
    // while (fin)
    // {
    // cout << i << endl;
    // fin.read ((char*)&i, sizeof(int));
    // };
    // fin.close ();

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fout ("integers.bin", ios::out | ios::binary);


    int i=1;
    fout.write ((char*)&i, sizeof(int));

    char key[3];
    cout << "enter key: ";
    cin >> key;
    fout.write (key, 3);


    fout.close ();



    // int i;
    // fstream fin ("iofile.bin", ios::in);
    // fin.read ((char*)&i, sizeof(int));
    // while (fin)
    // {
    //     cout << i << endl;
    //     fin.read ((char*)&i, sizeof(int));
    // };
    // fin.close ();


    return 0;
}
