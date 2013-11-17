#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE* infile;
    FILE* oufile;

    // infile = fopen("paldies.in", "r");
    // oufile = fopen("paldies.out", "w+");

    fprintf(stdout, "ok?");

    fclose(infile);
    fclose(oufile);
    return 0;
}