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
        if (!feof(infile))
        {
            fscanf(infile, "%d", &number);
            numbers[i] = number;
        }
        else
        {
            break;
        }
    }

    if (i == 0)
    {
        fprintf(oufile, "%s", "Nav skaitlu");
    }
    else
    {
        while (i > 0)
        {
            i--;
            fprintf(oufile, "%d%s", numbers[i], " ");
        }
    }

    fclose(infile);
    fclose(oufile);
    return 0;
}