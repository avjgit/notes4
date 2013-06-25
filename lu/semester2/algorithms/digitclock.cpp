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
    void print0(){
        //upper line
        line();
        //first half
        for (int i = 0; i < size; i++){
            cout << "|";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        //middle line
        cout << "|";
        for (int i = 0; i < size; i++) cout << " ";
        cout << "|" << endl;
        //second half
        for (int i = 0; i < size; i++){
            cout << "|";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        // bottom line
        line();
    }
    void print1(){
        //upper line
        cout << " ";
        for (int i = 0; i < size; i++) cout << " ";
        cout << "|" << endl;
        //first half
        for (int i = 0; i < size; i++){
            cout << " ";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        //middle line
        cout << " ";
        for (int i = 0; i < size; i++) cout << " ";
        cout << "|" << endl;
        //second half
        for (int i = 0; i < size; i++){
            cout << " ";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        // bottom line
        cout << " ";
        for (int i = 0; i < size; i++) cout << " ";
        cout << "|" << endl;
    }
    void print2(){
        //upper line
        // cout << "-";
        // for (int i = 0; i < size; i++) cout << "-";
        // cout << "-" << endl;
        line();

        //first half
        for (int i = 0; i < size; i++){
            cout << " ";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        //middle line
        // cout << "-";
        // for (int i = 0; i < size; i++) cout << "-";
        // cout << "-" << endl;
        line();

        //second half
        for (int i = 0; i < size; i++){
            cout << "|";
            for (int i = 0; i < size; i++) cout << " ";
            cout << " " << endl;
        }
        // bottom line
        line();

    }
    void print3(){
        //upper line
        line();
        //first half
        for (int i = 0; i < size; i++){
            cout << " ";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        //middle line
        line();
        //second half
        for (int i = 0; i < size; i++){
            cout << " ";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        // bottom line
        line();

    }
    void print4(){
        //upper line
        cout << "|";
        for (int i = 0; i < size; i++) cout << " ";
        cout << "|" << endl;
        //first half
        for (int i = 0; i < size; i++){
            cout << "|";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        //middle line
        line();

        //second half
        for (int i = 0; i < size; i++){
            cout << " ";
            for (int i = 0; i < size; i++) cout << " ";
            cout << "|" << endl;
        }
        // bottom line
        cout << " ";
        for (int i = 0; i < size; i++) cout << " ";
        cout << " " << endl;
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