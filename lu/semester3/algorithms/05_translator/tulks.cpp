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

    letter* lang_A = new letter;
    letter* lang_B = new letter;
    letter *lang_From, *curr_A, *curr_B;

    char word_a[20];
    char word_b[20];
    int c;

    ///////////////////// read in dictionary
    for(;;){
        fscanf(in, "%s", word_a);

        //check if end of dictionary; define translation direction
        if (word_a[0] == '<'){ lang_From = lang_B; break; }
        if (word_a[2] == '>'){ lang_From = lang_A; break; }

        ////////////////////////////// READ WORD A
        // pseudocode: transform wordA chars to letters structure
        curr_A = lang_A; // set cursor to beginning of tree of characters

        for(int i = 0; word_a[i] != '\0'; i++){

            c = word_a[i]; // transferring character to integer (eg., A is 65)

            if (curr_A->next[c] == NULL){
                curr_A->next[c]       = new letter;
                curr_A->next[c]->self = word_a[i];
                curr_A->next[c]->prev = curr_A;
            }
            curr_A = curr_A->next[c];
        }

        ////////////////////////////// READ WORD B
        // pseudocode: transform wordB chars to letters structure

        fscanf(in, "%s", word_b);

        // fix - if translation is known already - do not fill B translation
        if (curr_A->translation != NULL) continue;

        curr_B = lang_B; // set cursor to beginning of tree of characters

        for(int i = 0; word_b[i] != '\0'; i++){

            c = word_b[i]; // transferring character to integer (eg., A is 65)

            if (curr_B->next[c] == NULL){
                curr_B->next[c]       = new letter;
                curr_B->next[c]->self = word_b[i];
                curr_B->next[c]->prev = curr_B;
            }
            curr_B = curr_B->next[c];
        }
        curr_B = curr_B;

        // pseudocode: point translation to each other
        curr_A->translation = curr_B;
        curr_B->translation = curr_A;
    }
    ///////////////////// translation and output
    char word[20];
    char word_translation_stack[20];
    int char_count;
    bool is_translated;
    letter* curr = lang_From;

    fscanf(in, "%s", word);
    while (!feof(in)){
        curr = lang_From;
        // pseudocode: per word characters, get from start till last char
        is_translated = true;
        for(int i = 0; word[i] != '\0'; i++){

            c = word[i]; // transferring character to integer (eg., A is 65)
            if (curr->next[c] != NULL){
                curr = curr->next[c];
            }
            else{
                is_translated = false;
                break;
            }
        }

        if(is_translated)
            is_translated = (curr->translation != NULL);

        if (is_translated){
            char_count = -1;
            curr = curr->translation; //set pointer to translation
            do{
                char_count++; // fill translation stack
                word_translation_stack[char_count] = curr->self;
                curr = curr->prev; //go up from curr letter till language root
            }while(curr->prev != NULL);

            while(char_count >= 0) // output translation stack
                fprintf(out, "%c", word_translation_stack[char_count--]);
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
