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
    const int MAX_WORD_SIZE = 40;
    char  c;                     // character to read in
    char  word[MAX_WORD_SIZE];   // array to save a word read in
    int   word_length;

    ifstream f1 ("f1");          // file to read text from
    ifstream f2 ("f2");          // file to check replacements
    ofstream f3 ("f3");          // file to output result

    c = f1.get();

    while (!f1.eof()) {

        word_length = 0;

        // char by char, read the word from f1
        while (!is_end_of_word(c))
        {
            word[word_length] = c;
            word_length++;
            c = f1.get();
        }

        // check if it exists in f2

        // if does, then replace it with pair from f2

        // output to f3
        cout << "got this word: ";
        for (int i = 0; i < word_length; i++)
        {
            // f3 << word[i];
            cout << word[i];

        }
        cout << endl;

        c = f1.get();
    }


    f1.close();
    f2.close();
    f3.close();
    return 0;
}
