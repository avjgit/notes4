#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE* infile;
    FILE* oufile;

    infile = fopen("komanda.in", "r");
    oufile = fopen("komanda.out", "w+");

    long long parent, left, right;

    parent = 3999999997;

    while (!feof(infile))
    {
        fscanf(infile, "%lld %lld %lld", &parent, &left, &right);
        fprintf(oufile, "%lld %lld %lld", parent, left, right);
    }

    fclose(infile);
    fclose(oufile);
    return 0;
}