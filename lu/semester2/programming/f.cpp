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

int main()
{
    // tests of is_end_of_word
    // if (is_end_of_word('a')) {cout << "nok";} else {cout << "ok";}
    // if (is_end_of_word(' ')) {cout << "ok";} else {cout << "nok";}
    // if (is_end_of_word('?')) {cout << "ok";} else {cout << "nok";}

    char c;             // character to read in
    char word[40];      // array to save a word read in
    ifstream f1 ("f1");
    ifstream f2 ("f2");
    ofstream f3 ("f3");


    // read the word from f1
    // check if it exists in f2
    // if does, then replace it with pair from f2
    // output to f3

    c = f1.get();
    while (!f1.eof()) {
        cout << c;
        f3 << c;
        c = f1.get();
    }

    f1.close();
    f2.close();
    f3.close();
    return 0;
}
