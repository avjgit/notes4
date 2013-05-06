#include "stdio.h"
#include "stdlib.h"
struct number_link
{
    int number;
    number_link* previous;
};
int main()
{
    FILE* infile;
    FILE* oufile;
    infile = fopen("reverse.in", "r");
    oufile = fopen("reverse.out", "w+");

    int amount;
    fscanf(infile, "%d", &amount);

    // test
    fprintf(stdout, "There will be %d numbers\n", amount);

    if (amount == 0)
    {
        amount = 100;
    }

    int* numbers;
    numbers = new int[amount];
    int number;
    int i = 0;

    number_link* current;
    number_link* last = NULL;

    for(i = 0; i < amount; i++)
    {
        fprintf(stdout, "inside, step %d\n", i);

        if (!feof(infile))
        {
            fscanf(infile, "%d", &number);
            // numbers[i] = number;
            current = new number_link;
            current->number = number;
            current->previous = last;
            last = current;

            fprintf(stdout, "wrote %d\n", number);
        }
        else
        {
            fprintf(stdout, "end of file\n");
            break;
        }
    }

    if (i == 0)
    {
        fprintf(oufile, "%s", "Nav skaitlu");
        fprintf(stdout, "printed Nav skaitlu\n");
    }
    else
    {
        while (i > 0)
        {
            i--;
            // fprintf(oufile, "%d%s", numbers[i], " ");
            // fprintf(stdout, "put %d number - %d\n", i, numbers[i]);
            fprintf(oufile, "%d%s", last->number, " ");
            fprintf(stdout, "put %d th number - %d\n", i, last->number);
            last = last->previous;
        }
    }

    fclose(infile);
    fclose(oufile);
    return 0;
}