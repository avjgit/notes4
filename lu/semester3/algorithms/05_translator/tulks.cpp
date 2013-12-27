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
    letter* current = language_From;
    letter* last_A = NULL;
    letter* last_B = NULL;
    letter* new_letter;

    // todo: this is testline; remove
    current->next_letters[97] = language_B;

    char word_a[20];
    char word_b[20];
    int char2int;

    ///////////////////// read in dictionary
    for(;;){
        fscanf(in, "%s", word_a);
        fprintf(stdout, "\nword A: %s: ", word_a);

        ///////////////////// check if end of dictionary; define translation direction
        if (word_a[0] == '-'){
            if (word_a[2] == '<') language_From = language_B;
            break;
        }
        ////////////////////////////// READ WORD A
        // pseudocode: transform wordA chars to letters structure
        current = language_A; // set cursor to beginning of tree of characters

        for(int i = 0; word_a[i] != '\0'; i++){

            char2int = word_a[i]; // transferring character to integer (eg., A is 65)

            if (current->next_letters[char2int] == NULL){
                new_letter = new letter;
                new_letter->self = word_a[i];
                new_letter->previous_letter = current;
                current->next_letters[char2int] = new_letter;
                fprintf(stdout, "%i", word_a[i], " ");
            }
            else{
                fprintf(stdout, "%i letter is known!", word_a[i]);
            }
            current = current->next_letters[char2int];
            fprintf(stdout, "-");
        }
        last_A = current;

        ////////////////////////////// READ WORD B
        fscanf(in, "%s", word_b);
        fprintf(stdout, "\nword B: %s: ", word_b);

        current = language_B; // set cursor to beginning of tree of characters

        for(int i = 0; word_b[i] != '\0'; i++){

            char2int = word_b[i]; // transferring character to integer (eg., A is 65)

            if (current->next_letters[char2int] == NULL){
                new_letter = new letter;
                new_letter->self = word_b[i];
                new_letter->previous_letter = current;
                current->next_letters[char2int] = new_letter;
                fprintf(stdout, "%i", word_b[i], " ");
            }
            else{
                fprintf(stdout, "%i letter is known!", word_b[i]);
            }
            current = current->next_letters[char2int];
            fprintf(stdout, "-");
        }
        fprintf(stdout, "\n----------");

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
