#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string key;
    int int1, int2;
    ifstream infile ("addition.in");
    ofstream oufile ("addition.out");

    infile >> key;
    infile >> int1;
    infile >> int2;
    oufile << key << ": " << int1 + int2;

    infile.close();
    oufile.close();
    cout << "ok?";
    return 0;
}