#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile ("k.in");
    long length;
    int* profits = NULL;
    // MAIN ALGORITHM
    infile >> length;
    profits = new int[length-1];

    int dayprofit;
    for(int i = 0; i < length; i++){
        infile >> dayprofit;
        // cout << "day: " << dayprofit;
        profits[i] = dayprofit;
    }

    for(int i = 0; i < length; i++){
        cout << "profit for day " << i << " is " << profits[i] << endl;
    }

    infile.close();
    return 0;
}