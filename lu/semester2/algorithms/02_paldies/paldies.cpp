#include "stdio.h"
#include "stdlib.h"
struct card
{
    char address[255];
    card* previous;
};

int alphabet_letter_number(char alphabet_letter)
{
    return (int)alphabet_letter - (int)'a';
}

int main()
{
    FILE* infile;
    FILE* oufile;

    infile = fopen("paldies.in", "r");
    oufile = fopen("paldies.out", "w+");

    card*  current = NULL;

    const int ALPHABET_SIZE = 26;
    card* alphabet[ALPHABET_SIZE];

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        alphabet[i] = NULL;
    }

    bool is_empty = true;

    if (fgetc(infile) == EOF)
    {
        is_empty = true;
    }
    else
    {
        is_empty = false;
        fclose(infile);
        infile = fopen("paldies.in", "r");
    }

    int letter_number;

    while (!feof(infile))
    {
        current = new card;
        fscanf(infile, "%s", current->address);

        letter_number = alphabet_letter_number((current->address)[0]);

        current->previous = alphabet[letter_number];
        alphabet[letter_number] = current;
    }

    if (is_empty)
    {
        fprintf(oufile, "%s", "nothing");
    }
    else
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            while (alphabet[i] != NULL)
            {
                fprintf(oufile, "%s%s", alphabet[i]->address, " ");
                alphabet[i] = alphabet[i]->previous;
            }
        }
    }

    fclose(infile);
    fclose(oufile);
    return 0;
}