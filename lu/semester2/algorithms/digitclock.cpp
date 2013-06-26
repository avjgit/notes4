#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Clock{
    static const int D = 6;
    static const int MAX_HH = 24;
    static const int MAX_MM = 60;
    int hh, mm, ss, size, digits[D];
    ofstream outstream;
public:
    Clock() : outstream("clock.txt", ios::app) {}
    Clock(int hh_, int mm_, int ss_, int size_=1)
    : outstream("clock.txt", ios::app)
    {
        hh = hh_ % MAX_HH;
        mm = mm_ % MAX_MM;
        ss = ss_ % MAX_MM;

        digits[0]  = hh / 10;
        digits[1]  = hh % 10;
        digits[2]  = mm / 10;
        digits[3]  = mm % 10;
        digits[4]  = ss / 10;
        digits[5]  = ss % 10;
        size = size_;

        outstream << "clock " << hh << " : " << mm << " : " << ss << endl;

        // print upper
        for(int i = 0; i < D; i++) {
            switch(digits[i]){
                case 0: print0_upper(); break;
                case 1: print1_upper(); break;
                case 2: print2_upper(); break;
                case 3: print3_upper(); break;
                case 4: print4_upper(); break;
                case 5: print5_upper(); break;
                case 6: print6_upper(); break;
                case 7: print7_upper(); break;
                case 8: print8_upper(); break;
                case 9: print9_upper(); break;
            }
            print_empty_delimeter(i);
        }
        outstream << endl;
        // print first half
        for (int k = 0; k < size; k++){
            for(int i = 0; i < D; i++) {
                switch(digits[i]){
                    case 0: print0_uphalf(); break;
                    case 1: print1_uphalf(); break;
                    case 2: print2_uphalf(); break;
                    case 3: print3_uphalf(); break;
                    case 4: print4_uphalf(); break;
                    case 5: print5_uphalf(); break;
                    case 6: print6_uphalf(); break;
                    case 7: print7_uphalf(); break;
                    case 8: print8_uphalf(); break;
                    case 9: print9_uphalf(); break;
                }
                print_delimeter(i);
            }
            outstream << endl;
        }
        // print middle
        for(int i = 0; i < D; i++) {
            switch(digits[i]){
                case 0: print0_middle(); break;
                case 1: print1_middle(); break;
                case 2: print2_middle(); break;
                case 3: print3_middle(); break;
                case 4: print4_middle(); break;
                case 5: print5_middle(); break;
                case 6: print6_middle(); break;
                case 7: print7_middle(); break;
                case 8: print8_middle(); break;
                case 9: print9_middle(); break;
            }
            print_empty_delimeter(i);
        }
        outstream << endl;

        // print second half
        for (int k = 0; k < size; k++){
            for(int i = 0; i < D; i++) {
                switch(digits[i]){
                    case 0: print0_downhalf(); break;
                    case 1: print1_downhalf(); break;
                    case 2: print2_downhalf(); break;
                    case 3: print3_downhalf(); break;
                    case 4: print4_downhalf(); break;
                    case 5: print5_downhalf(); break;
                    case 6: print6_downhalf(); break;
                    case 7: print7_downhalf(); break;
                    case 8: print8_downhalf(); break;
                    case 9: print9_downhalf(); break;
                }
                print_delimeter(i);
            }
            outstream << endl;
        }
        // print bottom
        for(int i = 0; i < D; i++) {
            switch(digits[i]){
                case 0: print0_bottom(); break;
                case 1: print1_bottom(); break;
                case 2: print2_bottom(); break;
                case 3: print3_bottom(); break;
                case 4: print4_bottom(); break;
                case 5: print5_bottom(); break;
                case 6: print6_bottom(); break;
                case 7: print7_bottom(); break;
                case 8: print8_bottom(); break;
                case 9: print9_bottom(); break;
            }
            print_empty_delimeter(i);
        }
        outstream << endl;
    }

    void empty_middle() {for (int i = 0; i < size; i++) outstream << " ";}
    void full_line()    {for (int i = 0; i < size; i++) outstream << "-";}

    void print_empty_delimeter(int i)    {if ((i == 1) || (i == 3)) outstream << " ";}
    void print_delimeter(int i)    {if ((i == 1) || (i == 3)) outstream << "*";}

    void line()         {outstream << " "; full_line();    outstream << " ";}
    void empty_line()   {outstream << " "; empty_middle(); outstream << " ";}
    void double_line()  {outstream << "|"; empty_middle(); outstream << "|";}
    void right_line()   {outstream << " "; empty_middle(); outstream << "|";}
    void left_line()    {outstream << "|"; empty_middle(); outstream << " ";}

    void print0_upper()     {line();}
    void print0_uphalf()    {double_line();}
    void print0_middle()    {double_line();}
    void print0_downhalf()  {double_line();}
    void print0_bottom()    {line();}

    void print1_upper()     {empty_line();}
    void print1_uphalf()    {right_line();}
    void print1_middle()    {right_line();}
    void print1_downhalf()  {right_line();}
    void print1_bottom()    {right_line();}

    void print2_upper()     {line();}
    void print2_uphalf()    {right_line();}
    void print2_middle()    {line();}
    void print2_downhalf()  {left_line();}
    void print2_bottom()    {line();}

    void print3_upper()     {line();}
    void print3_uphalf()    {right_line();}
    void print3_middle()    {line();}
    void print3_downhalf()  {right_line();}
    void print3_bottom()    {line();}

    void print4_upper()     {empty_line();}
    void print4_uphalf()    {double_line();}
    void print4_middle()    {line();}
    void print4_downhalf()  {right_line();}
    void print4_bottom()    {right_line();}

    void print5_upper()     {line();}
    void print5_uphalf()    {left_line();}
    void print5_middle()    {line();}
    void print5_downhalf()  {right_line();}
    void print5_bottom()    {line();}

    void print6_upper()     {line();}
    void print6_uphalf()    {left_line();}
    void print6_middle()    {line();}
    void print6_downhalf()  {double_line();}
    void print6_bottom()    {line();}

    void print7_upper()     {line();}
    void print7_uphalf()    {right_line();}
    void print7_middle()    {right_line();}
    void print7_downhalf()  {right_line();}
    void print7_bottom()    {empty_line();}

    void print8_upper()     {line();}
    void print8_uphalf()    {double_line();}
    void print8_middle()    {line();}
    void print8_downhalf()  {double_line();}
    void print8_bottom()    {line();}

    void print9_upper()     {line();}
    void print9_uphalf()    {double_line();}
    void print9_middle()    {line();}
    void print9_downhalf()  {right_line();}
    void print9_bottom()    {line();}

};

int main(){
    Clock *clock;

    clock = new Clock (19, 23, 45, 1); delete clock;
    clock = new Clock ( 6,  7,  8, 1); delete clock;
    clock = new Clock (19, 23, 45, 2); delete clock;
    clock = new Clock ( 6,  7,  8, 2); delete clock;
    clock = new Clock (19, 23, 45, 3); delete clock;
    clock = new Clock ( 6,  7,  8, 3); delete clock;
    clock = new Clock (19, 23, 45, 4); delete clock;
    clock = new Clock ( 6,  7,  8, 4); delete clock;

    return 0;
}