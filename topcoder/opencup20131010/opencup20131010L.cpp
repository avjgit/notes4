#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <limits.h>
using namespace std;

long volume(int w, int h, int l)
{
    return w * h * l;
}

long side(int dim1, int dim2, long v)
{
    return v / dim1 / dim2;
}

int main()
{

    ifstream infile ("l.in");
    int w, h, l;
    long V;

    infile >> w;
    infile >> h;
    infile >> l;
    infile >> V;

    while (w != 0 || h != 0 || h != 0 || V != 0){

        if (V == 0){
            V = volume(w, h, l);
        }
        else {
            if (w == 0) w = side(h, l, V);
            if (h == 0) h = side(w, l, V);
            if (l == 0) l = side(w, h, V);
        }

        cout << w << " " << h << " " << l << " " << V << endl;

        infile >> w;
        infile >> h;
        infile >> l;
        infile >> V;

    }

    // long product, max_product;

    // max_product = 1;
    // for (long i = 1; i <= N; i++)
    // {
    //     product = product_digits(i);
    //     if (product > max_product) {
    //         max_product = product;
    //     }
    // }
    // cout << max_product;

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


    // infile.close();
    return 0;
}