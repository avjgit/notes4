// Andrejs Jurcenoks aj05044 DSuPII PD5
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/05_translator/tulks.cpp

#include <fstream>
struct letter{
    char self;
    letter* prev; //previous_letter
    letter* translation;
    letter* next[128]; // ASCII size array of all possible next letters
    letter(){
        self = '.';
        prev = NULL;
        translation = NULL;
        for(int i = 0; i < 128; i++) next[i] = NULL;
    }
};

int main() {
    FILE* in    = fopen("tulks.in", "r");
    FILE* out   = fopen("tulks.out", "w+");

    letter* language_A = new letter;
    letter* language_B = new letter;
    letter* language_From = language_A;
    letter* curr = language_From;
    letter* curr_A = NULL;
    letter* curr_B = NULL;
    letter* new_letter;

    char word_a[20];
    char word_b[20];
    int char2int;

    ///////////////////// read in dictionary
    for(;;){
        fscanf(in, "%s", word_a);
        // fprintf(stdout, "\nword A: %s: ", word_a);

        //check if end of dictionary; define translation direction
        if (word_a[0] == '<'){ language_From = language_B; break; }
        if (word_a[2] == '>'){ language_From = language_A; break; }

        ////////////////////////////// READ WORD A
        // pseudocode: transform wordA chars to letters structure
        curr_A = language_A; // set cursor to beginning of tree of characters

        for(int i = 0; word_a[i] != '\0'; i++){

            char2int = word_a[i]; // transferring character to integer (eg., A is 65)

            if (curr_A->next[char2int] == NULL){
                curr_A->next[char2int]       = new letter;
                curr_A->next[char2int]->self = word_a[i];
                curr_A->next[char2int]->prev = curr_A;
                // fprintf(stdout, "%i", word_a[i], " ");
            }
            else{
                // fprintf(stdout, "%i letter is known!", word_a[i]);
            }
            curr_A = curr_A->next[char2int];
            // fprintf(stdout, "-");
        }

        ////////////////////////////// READ WORD B
        // pseudocode: transform wordB chars to letters structure

        fscanf(in, "%s", word_b);
        // fprintf(stdout, "\nword B: %s: ", word_b);

        // fix - if translation is known already - do not fill B translation
        if (curr_A->translation != NULL) continue;

        curr_B = language_B; // set cursor to beginning of tree of characters

        for(int i = 0; word_b[i] != '\0'; i++){

            char2int = word_b[i]; // transferring character to integer (eg., A is 65)

            if (curr_B->next[char2int] == NULL){
                new_letter = new letter;
                new_letter->self = word_b[i];
                new_letter->prev = curr_B;
                curr_B->next[char2int] = new_letter;
                // fprintf(stdout, "%c-", word_b[i], " ");
            }
            else{
                // fprintf(stdout, "%c letter is known!-", word_b[i]);
            }
            curr_B = curr_B->next[char2int];
        }
        curr_B = curr_B;

        // fprintf(stdout, "\n----------");

        // pseudocode: point from wordB last char to wordA last char
        curr_A->translation = curr_B;
        // pseudocode: point from wordA last char to wordB last char
        curr_B->translation = curr_A;
    }
    ///////////////////// translation and output
    char word[20];
    char word_translation_stack[20];
    int char_count;
    bool is_translation_found;

    fscanf(in, "%s", word);
    while (!feof(in)){
        // fprintf(stdout, "\nchecking %s: ", word);
        curr = language_From;
        // pseudocode: per word characters, get from start till last char
        is_translation_found = true;
        for(int i = 0; word[i] != '\0'; i++){
            // fprintf(stdout, " %c: ", word[i]);

            char2int = word[i]; // transferring character to integer (eg., A is 65)
            if (curr->next[char2int] != NULL){
                // fprintf(stdout, "ok");
                curr = curr->next[char2int];
            }
            else{
                // fprintf(stdout, "unknown!");
                is_translation_found = false;
                break;
            }
        }

        if(is_translation_found)
            is_translation_found = (curr->translation != NULL);

        if (is_translation_found){
        // pseudocode: else, set pointer to translation
        // pseudocode: go up from curr letter till language root, filling stack
        // pseudocode: output stack
            char_count = -1;
            curr = curr->translation;
            // fprintf(out, "translatable! ");

            do{
                char_count++;
                word_translation_stack[char_count] = curr->self;
                // fprintf(stdout, "saved %c; ", curr->self);
                curr = curr->prev;
            }while(curr->prev != NULL);

            while(char_count >= 0){
                fprintf(out, "%c", word_translation_stack[char_count]);
                char_count--;
            }
        }
        else
            fprintf(out, "?%s", word);
        fprintf(out, " ");
        fscanf(in, "%s", word);
    }
    fclose(in);
    fclose(out);
    return 0;
}
