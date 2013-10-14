#include <iostream>
#include <fstream>
using namespace std;

bool is_end_of_word(char c)
{
    char separators[] = {' ', '.', ',', '(', ')', '!', '?'};
    int arrSize = sizeof(separators) / sizeof(char);
    for (int i = 0; i < arrSize; i++)
    {
        if (separators[i] == c)
        {
            return true;
        }
    }
    return false;
}

struct searchchar{
    char c;
    searchchar* next;
};

struct found{
    int position;
    found* next;
};

int main()
{
    ifstream searchfile("word.in");
    ofstream outfile("out.out");

    found* curr_found;
    found* prev_found;
    found* first_found = NULL;

    searchchar* current;
    searchchar* previous;
    searchchar* first = NULL;
    int length = 0;

    char curc;
    searchfile >> curc;
    while(!searchfile.eof())
    {
        length++;

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

        searchfile >> curc;
    }

    // current = first;
    // while (current != NULL){
    //     cout << current->c;
    //     current = current->next;
    // }

    ifstream infile ("text.in");

    bool new_word = true;
    int pos = 0;

    infile >> noskipws >> curc;
    pos++;
    cout << "char: " << curc << ", pos: " << pos;

    while(infile.good())
    {
        current = first;
        for(int i = 0; i < length && new_word; i++)
        {
            // cout << endl << "i: " << i;
            cout << endl << "evaluating " << curc << "...";

            if(curc == current->c){
                cout << "ok, char " << curc << " found";
                current = current->next;
                if (i == length-1){
                    infile >> noskipws >> curc;
                    pos++;
                    cout << "char: " << curc << ", pos: " << pos;

                    cout << "checking " << curc << endl;

                    if (is_end_of_word(curc)){

                        cout << "found word! at " << pos-length << endl;

                        curr_found = new found;
                        curr_found->position = pos;
                        curr_found->next = NULL;

                        if (first_found == NULL) {
                            first_found = curr_found;
                        }
                        else {
                            prev_found->next = curr_found;
                        }
                        prev_found = curr_found;
                    }
                }
                infile >> curc;
                pos++;
                cout << "char: " << curc << ", pos: " << pos;
            }
            else{
                while(!is_end_of_word(curc)){
                    infile >> noskipws >> curc;
                    pos++;
                    cout << "char: " << curc << ", pos: " << pos;
                    cout << endl << "skipping, took " << curc;
                }
                new_word = false;
            }

        }

        infile >> curc;
        pos++;
        cout << "char: " << curc << ", pos: " << pos;
        new_word = true;
    }
    cout << "out of loop" << endl;

    // int cfound = first_found->position;
    // cout << cfound;

    // curr_found = first_found;
    // while(curr_found->next != NULL)
    // {
    //     // cout << "found " << curr_found->position;
    //     // outfile << curr_found->position;
    //     // outfile << " ";
    //     curr_found = curr_found->next;
    // }

    infile.close();
    return 0;
}