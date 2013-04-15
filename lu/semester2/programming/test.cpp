#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fv;
    float num;

    fv.open("myfile.dat", ios::out);
    for(int i = 1; i<= 10; i++)
    {
        cout << "enter number: ";
        cin >> num;
        fv.write((char*)&num, sizeof(num));
    }
    fv.close();
    return 0;
}