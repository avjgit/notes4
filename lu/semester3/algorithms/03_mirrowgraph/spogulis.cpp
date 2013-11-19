#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE* in;
    FILE* out;
    // todo: tests to pass 1 by 1: 2 3 4 5 6 7 8
    // todo: tests to pass with final: 1 2 3 4 5 6 7 8
    //todo: real name: "spogulis.in"
    in = fopen("spogulis.i2.txt", "r");
    out = fopen("spogulis.out", "w+");
    int node = 0;

    fscanf(in, "%i", &node);
    while (!feof(in))
    {
    	fprintf(out, "%i\n", node);
        fscanf(in, "%i", &node);
    }

    fclose(in);
    fclose(out);
    return 0;
}