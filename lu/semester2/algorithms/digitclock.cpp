#include <iostream>
#include <stdlib.h>
using namespace std;

class Clock{
    int size;
public:
    Clock(int size_){
        size = max(1, size_);
    }
    Clock(){
        size = 1;
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
};

int main(){
    Clock clock;
    clock.print0();
    clock.print1();
    clock.print2();
    clock.print3();
    clock.print4();
    return 0;
}