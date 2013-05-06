#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int* numbers;
    ifstream infile ("reverse.in");
    ofstream oufile ("reverse.out");

    int amount;
    infile >> amount;
    if (amount == 0)
    {
        amount = 100;
    }

    numbers = new int[amount];
    int number;
    int i = 0;
    while (!infile.eof())
    {
        for(i = 0; i < amount; i++)
        {
            infile >> number;
            numbers[i] = number;
        }
    }

    if (i == 0)
    {
        oufile << "Nav skaitlu";
    }
    else
    {
        while (i > 0)
        {
            i--;
            oufile << numbers[i] << " ";
        }
    }

    infile.close();
    oufile.close();
    return 0;
}