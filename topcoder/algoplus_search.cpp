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

    current = first;
    while (current != NULL){
        cout << current->c;
        current = current->next;
    }

    ifstream infile ("text.in");

    while(infile.good())
    {
        infile >> curc;

        current = first;
        for(int i = 0; i < length; i++)
        {
            if(curc == current->c){
                current = current->next;
                if (i == length-1){
                    infile >> curc;
                    if (is_end_of_word(curc)){

                        curr_found = new found;
                        curr_found->position = i;
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
            }
            else{
                while(!is_end_of_word(curc))
                    infile >> curc;
                break;
            }
        }
    }

    // char cfound = first_found->position;
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