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
    char  c, c2;                 // character to read in from f1, f2
    char  word [MAX_WORD_SIZE];  // a word read in from f1
    char  pair1[MAX_WORD_SIZE];  // first word from pair from f2
    char  pair2[MAX_WORD_SIZE];  // second word from pair from f2
    const char WORD_SEPARATOR = ' ';    // separates words in pair
    const char PAIR_SEPARATOR = ',';    // separates pairs in file
    int   word_length;
    int   pair1_length;
    int   pair2_length;
    bool  is_word_in_pair;


    ifstream f1 ("f1");          // file to read text from
    ifstream f2;                 // file to check replacements
    ofstream f3 ("f3");          // file to output result

    c = f1.get();

    while (!f1.eof()) {


        // char by char, read the word from f1
        word_length = 0;
        while (!f1.eof() && !is_end_of_word(c))
        {
            word[word_length] = c;
            word_length++;
            c = f1.get();
        }

        // check if it exists in f2
        f2.open("f2");
        c2 = f2.get();
        while(!f2.eof())
        {
            // read first word from pair
            pair1_length = 0;

            while (!f2.eof() && c2 != WORD_SEPARATOR)
            {
                pair1[pair1_length] = c2;
                pair1_length++;
                c2 = f2.get();
            }

            // if this is word from input file (f1)
            is_word_in_pair = false;
            if (word_length == pair1_length)
            {
                is_word_in_pair = true;
                for(int i = 0; i < word_length; i++)
                {
                    if (word[i] != pair1[i])
                    {
                        is_word_in_pair = false;
                        break;
                    }
                }
            }

            if (is_word_in_pair)
            {
                word[0] = 'X';
            }

            c2 = f2.get();
        }
        f2.close();

        // output to f3
        for (int i = 0; i < word_length; i++)
        {
            f3 << word[i];
        }

        // copy punctuation to the file as well
        if (!f1.eof())
        {
            f3 << c;
        }
        c = f1.get();
    }

    f1.close();
    f3.close();
    return 0;
}
