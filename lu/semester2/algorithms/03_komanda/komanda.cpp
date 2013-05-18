#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE* infile = fopen("komanda.in", "r");
    FILE* oufile = fopen("komanda.out", "w+");

    long long parent, left, right;

    while (!feof(infile))
    {
        fscanf  (infile, "%lld %lld %lld", &parent, &left, &right);
        fprintf (oufile, "%lld %lld %lld",  parent,  left,  right);
    }

    fclose(infile);
    fclose(oufile);
    return 0;
}