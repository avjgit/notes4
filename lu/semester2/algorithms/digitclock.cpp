#include <iostream>
#include <stdlib.h>
using namespace std;

class Clock
{
    int left_border;
    int right_border;
    int up_border;
    int down_border;
    int middle_line;
    int width;
    int height;

public:
    Clock()
    {
        left_border = 1;
        right_border = 1;
        up_border = 1;
        down_border = 1;
        middle_line = 1;
    }
    Clock(int size)
    {
        *this = Clock();
        width = left_border + size + right_border;
        height = up_border + size + middle_line + size + down_border;
    }

    void print0(int size)
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
    clock.print0(1);
    return 0;
}