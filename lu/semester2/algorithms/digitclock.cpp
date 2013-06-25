#include <iostream>
#include <stdlib.h>
using namespace std;

class Clock
{
    // int left_border;
    // int right_border;
    // int up_border;
    // int down_border;
    // int middle_line;
    // int width;
    // int height;
    int size;
public:
    Clock()
    {
        Clock(1);
        // left_border = 1;
        // right_border = 1;
        // up_border = 1;
        // down_border = 1;
        // middle_line = 1;
    }
    Clock(int size_)
    {
        size = min(1, size_);
    }

    void print0()
    {
        cout << " ";
        for (int i = 0; i < size; i++) cout << "-";
        cout << " ";
        cout << endl;

        cout << "|";
        for (int i = 0; i < size; i++) cout << " ";
        cout << "|";
        cout << endl;

        cout << " ";
        for (int i = 0; i < size; i++) cout << "-";
        cout << " ";
        cout << endl;

    }
};

int main()
{
    Clock clock = Clock(1);
    clock.print0();
    return 0;
}