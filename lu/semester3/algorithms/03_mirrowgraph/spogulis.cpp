#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE* in;
    FILE* out;
    // todo: tests to pass: 1 2 3 4 5 6 7 8
    //todo: real name: "spogulis.in"
    in = fopen("spogulis.i1.txt", "r");
    out = fopen("spogulis.out", "w+");
    int node = 0;

    // while (!feof(in))
    // {
    	// fgetc( in);
    	fscanf(in, "%i", &node);
    	fprintf(out, "%s", "node is ");
    	fprintf(out, "%i", node);
    // }

    fclose(in);
    fclose(out);
    return 0;
}