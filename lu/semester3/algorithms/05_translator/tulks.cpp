// Andrejs Jurcenoks aj05044 DSuPII PD5
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/05_translator/tulks.cpp

#include <fstream>
// * Aizliegts izmantot jau gatavas datu struktūras (piemēram, String) un algoritmus (piemēram, qsort() un strcmp()).
struct letter{
    char self;
    letter* previous_letter;
    letter* translation;
    letter* next_letters[128]; // ASCII size array
    letter(){
        self = '.';
        previous_letter = NULL;
        translation = NULL;
        for(int i = 0; i < 128; i++) next_letters[i] = NULL;
    }
};

int main() {

    FILE* in = fopen("tulks.in", "r");
    FILE* out = fopen("tulks.out", "w+");

    letter* language_A = new letter;
    letter* language_B = new letter;
    letter* language_From = language_A;

    char word_a[20];
    char word_b[20];
    ///////////////////// read in dictionary
    for(;;){
        fscanf(in, "%s", word_a);
        ///////////////////// check if end of dictionary; define translation direction
        if (word_a[0] == '-'){
            if (word_a[2] == '<') language_From = language_B;
            break;
        }
        // pseudocode: transform wordA chars to letters structure
        fscanf(in, "%s", word_b);
        // pseudocode: transform wordB chars to letters structure
        // pseudocode: point from wordB last char to wordA last char
        // pseudocode: point from wordA last char to wordB last char
    }
    ///////////////////// translation and output
    char word[20];
    fscanf(in, "%s", word);
    while (!feof(in)){
        // pseudocode: per word characters, get from start till last char
        // pseudocode: if this word is not known (no pointer to last chare) - print out word with prefix "?"
        // pseudocode: else, set pointer to translation
        // pseudocode: go up from current letter till language root, filling stack
        // pseudocode: output stack
        fprintf(out, "%s%s", word, " ");
        fscanf(in, "%s", word);
    }
    fclose(in);
    fclose(out);
    return 0;
}
