#include <iostream>
#include <fstream>
using namespace std;

struct searchchar{
    char c;
    searchchar* next;
};


int main()
{
    ifstream searchfile("word.in");

    searchchar* current;
    searchchar* previous;
    searchchar* first = NULL;

    char curc;
    while(searchfile.good())
    {
        searchfile >> curc;

        current = new searchchar;
        current->c = curc;
        current->next = NULL;

        if (first == NULL) {
            first = current;
        }
        else {
            previous->next = current;
        }
        previous = current;
    }

    current = first;
    while (current != NULL){
        cout << current->c;
        current = current->next;
    }

    ifstream infile ("text.in");

    while(infile.good())
    {
        infile >> curc;



    }


    infile.close();
    return 0;
}