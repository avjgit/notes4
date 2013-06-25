#include <iostream>
#include <stdlib.h>
using namespace std;

class Clock{
    static const int D = 6;
    int size, HH, MM, SS, digits[D];
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
        for(int i = 0; i < D; i++) {
            switch(digits[i]){
                case 0: print0_upper(); break;
                case 2: print0_upper(); break;
                case 3: print0_upper(); break;
                case 4: print0_upper(); break;
                case 5: print0_upper(); break;
                case 6: print0_upper(); break;
                case 7: print0_upper(); break;
                case 8: print0_upper(); break;
                case 9: print0_upper(); break;
            }
        }
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
    void print0_upper()     {line();}
    void print0_uphalf()    {double_line();}
    void print0_middle()    {double_line();}
    void print0_downhalf()  {double_line();}
    void print0_bottom()    {line();}

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