#include "stdio.h"
#include "stdlib.h"
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

    for(i = 0; i < amount; i++)
    {
        fprintf(stdout, "inside, step %d\n", i);

        if (!feof(infile))
        {
            fscanf(infile, "%d", &number);
            numbers[i] = number;
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
            fprintf(oufile, "%d%s", numbers[i], " ");
            fprintf(stdout, "put %d number - %d\n", i, numbers[i]);
        }
    }

    fclose(infile);
    fclose(oufile);
    return 0;
}