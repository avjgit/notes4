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
    void print0(){
        //upper line
        cout << " ";
        for (int i = 0; i < size; i++) cout << "-";
        cout << " " << endl;
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
        cout << " ";
        for (int i = 0; i < size; i++) cout << "-";
        cout << " " << endl;
    }
};

int main(){
    Clock clock;
    clock.print0();
    return 0;
}