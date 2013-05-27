#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE *in = fopen("test.in", "r");
    FILE *out = fopen("test.out", "w+");

    long long test[0];

    test[4000000] = 42;

    fprintf(out, "%d", test[1]);

    return 0;
}