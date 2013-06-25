#include <iostream>
#include <stdlib.h>
using namespace std;

class Clock{
    int size, HH, MM, SS;
    int digits[6];
public:
    Clock(int HH_, int MM_, int SS_, int size_=1)
    {
        digits[0]  = HH_ / 10;
        digits[1]  = HH_ % 10;
        digits[2]  = MM_ / 10;
        digits[3]  = MM_ % 10;
        digits[4]  = SS_ / 10;
        digits[5]  = SS_ % 10;
        size = size_;
        // print upper
        // print first half
        // print middle
        // print second half
        // print bottom
    }
    void line()
    {
        cout << " ";
        for (int i = 0; i < size; i++) cout << "-";
        cout << " " << endl;
    }
    void double_line()
    {
        cout << "|";
        for (int i = 0; i < size; i++) cout << " ";
        cout << "|" << endl;
    }
    void right_line()
    {
        cout << " ";
        for (int i = 0; i < size; i++) cout << " ";
        cout << "|" << endl;
    }
    void left_line()
    {
        cout << "|";
        for (int i = 0; i < size; i++) cout << " ";
        cout << " " << endl;
    }

    void print0(){
        //upper line
        line();
        //first half
        for (int i = 0; i < size; i++){
            double_line();
        }
        //middle line
        double_line();
        //second half
        for (int i = 0; i < size; i++){
            double_line();
        }
        // bottom line
        line();
    }
    void print1(){
        //upper line
        right_line();
        //first half
        for (int i = 0; i < size; i++){
            right_line();
        }
        //middle line
        right_line();
        //second half
        for (int i = 0; i < size; i++){
            right_line();
        }
        // bottom line
        right_line();
    }
    void print2(){
        // upper line
        line();
        //first half
        for (int i = 0; i < size; i++){
            right_line();
        }
        //middle line
        line();
        //second half
        for (int i = 0; i < size; i++){
            left_line();
        }
        // bottom line
        line();
    }
    void print3(){
        //upper line
        line();
        //first half
        for (int i = 0; i < size; i++){
            right_line();
        }
        //middle line
        line();
        //second half
        for (int i = 0; i < size; i++){
            right_line();
        }
        // bottom line
        line();
    }
    void print4(){
        //upper line
        double_line();
        //first half
        for (int i = 0; i < size; i++){
            double_line();
        }
        //middle line
        line();
        //second half
        for (int i = 0; i < size; i++){
            right_line();
        }
        // bottom line
        right_line();
    }
    void print5(){
        //upper line
        line();
        //first half
        for (int i = 0; i < size; i++){
            left_line();
        }
        //middle line
        line();
        //second half
        for (int i = 0; i < size; i++){
            right_line();
        }
        // bottom line
        line();
    }
};

int main(){
    Clock clock = Clock(10, 23, 45);
    clock.print0();
    clock.print1();
    clock.print2();
    clock.print3();
    clock.print4();
    clock.print5();
    return 0;
}