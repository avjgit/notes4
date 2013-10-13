#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    ifstream infile ("m.in");
    int N;


    infile >> N;
    int length = floor(log10(N) + 1);
    // cout << "number is " << length << " long";

    int rest = N;
    // int x = pow(10, 2);
    int position, digit;
    for (int i = length; i > 0; i--)
    {
        position = pow(10, i-1);
        digit = rest / position;
        rest = rest % position;

        cout << "digit is " << digit << endl;
    }


    infile.close();
    return 0;
}