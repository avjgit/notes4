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
        // fprintf(stdout, "\nword A: %s: ", word_a);

        ///////////////////// check if end of dictionary; define translation direction
        if (word_a[1] == '-'){ // <-- or --> - both have common "-" in middle!
            if (word_a[0] == '<') language_From = language_B;
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
                // fprintf(stdout, "%i", word_a[i], " ");
            }
            else{
                // fprintf(stdout, "%i letter is known!", word_a[i]);
            }
            current = current->next_letters[char2int];
            // fprintf(stdout, "-");
        }
        last_A = current;

        ////////////////////////////// READ WORD B
        // pseudocode: transform wordB chars to letters structure

        fscanf(in, "%s", word_b);
        // fprintf(stdout, "\nword B: %s: ", word_b);

        // fix - if translation is known already - do not fill B translation
        if (last_A->translation != NULL) continue;

        current = language_B; // set cursor to beginning of tree of characters

        for(int i = 0; word_b[i] != '\0'; i++){

            char2int = word_b[i]; // transferring character to integer (eg., A is 65)

            if (current->next_letters[char2int] == NULL){
                new_letter = new letter;
                new_letter->self = word_b[i];
                new_letter->previous_letter = current;
                current->next_letters[char2int] = new_letter;
                // fprintf(stdout, "%c-", word_b[i], " ");
            }
            else{
                // fprintf(stdout, "%c letter is known!-", word_b[i]);
            }
            current = current->next_letters[char2int];
        }
        last_B = current;

        // fprintf(stdout, "\n----------");

        // pseudocode: point from wordB last char to wordA last char
        last_A->translation = last_B;
        // pseudocode: point from wordA last char to wordB last char
        last_B->translation = last_A;
    }
    ///////////////////// translation and output
    char word[20];
    char word_translation_stack[20];
    int word_length;
    bool is_translation_found;


    fscanf(in, "%s", word);

    while (!feof(in)){
        // fprintf(stdout, "\nchecking %s: ", word);
        current = language_From;
        // pseudocode: per word characters, get from start till last char
        is_translation_found = true;
        for(int i = 0; word[i] != '\0'; i++){
            // fprintf(stdout, " %c: ", word[i]);

            char2int = word[i]; // transferring character to integer (eg., A is 65)
            if (current->next_letters[char2int] != NULL){
                // fprintf(stdout, "ok");
                current = current->next_letters[char2int];
            }
            else{
                // fprintf(stdout, "unknown!");
                is_translation_found = false;
                break;
            }
        }

        if (is_translation_found){
        // pseudocode: else, set pointer to translation
        // pseudocode: go up from current letter till language root, filling stack
        // pseudocode: output stack
            word_length = -1;
            current = current->translation;
            // fprintf(out, "translatable! ");

            do{
                word_length++;
                word_translation_stack[word_length] = current->self;
                current = current->previous_letter;
            }while(current->previous_letter != NULL);

            while(word_length >= 0){
                fprintf(out, "%c", word_translation_stack[word_length]);
                word_length--;
            }
            fprintf(out, " ");


        }
        else{
        // pseudocode: if this word is not known (no pointer to last chare) - print out word with prefix "?"
        fprintf(out, "?%s%s", word, " ");
        }
        fscanf(in, "%s", word);
    }
    fclose(in);
    fclose(out);
    return 0;
}
