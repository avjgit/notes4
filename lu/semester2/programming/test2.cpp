#include <iostream>
using namespace std;

void change(int* p1, int* p2)
{
    p1 = p2;
}

int main()
{
    int a = 5;
    int b = 9;
    int* pa;
    int* pb;

    pa = &a;
    cout << *pa;

    pb = &b;
    change(pa, pb);

    cout << *pa;

    return 0;
}