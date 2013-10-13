#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

long product_digits(long number)
{
    int length = floor(log10(number) + 1);
    long rest = number;
    int position, digit;
    long sum = 1;
    for (int i = length; i > 0; i--)
    {
        position = pow(10, i-1);
        digit = rest / position;
        rest = rest % position;
        sum = sum * digit;
    }
    return sum;
}

int main()
{
    ifstream infile ("m.in");
    long N;

    infile >> N;
    long product, max_product, max_number;

    max_product = 1;
    for (long i = 1; i <= N; i++)
    {
        product = product_digits(i);
        if (product > max_product) {
            max_product = product;
            max_number = i;
        }
    }
    cout << "max is " << max_product << ", by " << max_number;

    // int length = floor(log10(N) + 1);
    // digits = new int[length-1];
    // // cout << "number is " << length << " long";

    // long rest = N;
    // // int x = pow(10, 2);
    // int position, digit;
    // for (int i = length, dig_i = 0; i > 0; i--, dig_i++)
    // {
    //     position = pow(10, i-1);
    //     digit = rest / position;
    //     digits[dig_i] = digit;
    //     rest = rest % position;

    //     cout << "digit is " << digit << endl;
    // }


    infile.close();
    return 0;
}