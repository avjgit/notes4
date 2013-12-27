// Andrejs Jurcenoks aj05044 DSuPII PD5
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/05_translator/tulks.cpp

#include <fstream>

struct letter{
    char self;
    letter* prev;       //previous_letter
    letter* next[128];  // ASCII size array of all possible next letters
    letter* translation;
    letter(){
        prev = NULL;
        for(int i = 0; i < 128; i++) next[i] = NULL;
        translation = NULL;
    }
};

letter* save(letter* dictionary_root, char* word){
    int c;
    // transform word characters to dictionary structure
    letter* cursor = dictionary_root;
    for(int i = 0; word[i] != '\0'; i++){

        c = word[i]; // transferring character to integer (eg., A is 65)

        if (cursor->next[c] == NULL){ // if this char is unknown yet
            cursor->next[c]       = new letter;
            cursor->next[c]->self = word[i];
            cursor->next[c]->prev = cursor;
        }
        cursor = cursor->next[c];
    }
    return cursor;
}

int main() {
    FILE *in    = fopen("tulks.in", "r");
    FILE *out   = fopen("tulks.out", "w+");

    letter *lang_A = new letter;
    letter *lang_B = new letter;
    letter *lang_From, *word_a, *word_b;

    char word[20];

    ///////////////////// read in dictionary
    for(;;){
        fscanf(in, "%s", word);

        //check if end of dictionary; define translation direction
        if (word[0] == '<'){ lang_From = lang_B; break; }
        if (word[2] == '>'){ lang_From = lang_A; break; }

        word_a = save(lang_A, word);

        fscanf(in, "%s", word);

        // fix - if translation is known already - do not fill B translation
        if (word_a->translation != NULL) continue;

        word_b = save(lang_B, word);

        // point translation to each other
        word_a->translation = word_b;
        word_b->translation = word_a;
    }
    ///////////////////// translation and output
    char   translation[20]; // word translation, saved as stack
    int    c;               // char's ASCII index
    int    chars;           // counting chars in word
    bool   is_known;        // does word exist in dictionary
    letter *curr;           // cursor to go through dictionary

    fscanf(in, "%s", word);
    while (!feof(in)){
        curr = lang_From;
        // per word characters, get from start till last char
        is_known = true;
        for(int i = 0; word[i] != '\0'; i++){

            c = word[i]; // transferring character to integer (eg., A is 65)
            if (curr->next[c] == NULL){
                is_known = false;
                break;
            }
            curr = curr->next[c];
        }

        if (is_known && curr->translation != NULL){
            chars = -1;
            curr = curr->translation; //set pointer to translation
            do {
                translation[++chars] = curr->self; // fill translation stack
                curr = curr->prev; //go up from curr letter till language root
            } while(curr->prev != NULL);
            // output translation stack
            while(chars >= 0) fprintf(out, "%c", translation[chars--]);
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
