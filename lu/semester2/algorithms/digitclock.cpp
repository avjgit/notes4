#include <iostream>
#include <stdlib.h>
using namespace std;

void print0(int size)
{
    cout << "/";
    cout << "-";
    cout << "\\";
    cout << "|";
    cout << " ";
    cout << "|";
    cout << "\\";
    cout << "-";
    cout << "/";
}
int main()
{
    cout << "hi" << endl;
    print0(0);
    cout << endl;
    system("pause");
    // getchar();
    return 0;
}