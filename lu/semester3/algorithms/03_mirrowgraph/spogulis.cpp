#include "stdio.h"
#include "stdlib.h"
//todo: remove
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//todo: end of remove

int main()
{
    ////////////////////////////////////////////////////////// implementation 1
    // FILE* in;
    // FILE* out;
    // todo: tests to pass 1 by 1: 2 3 4 5 6 7 8
    // todo: tests to pass with final: 1 2 3 4 5 6 7 8
    // todo: real name: "spogulis.in"
    // todo: correct formatting
    // in = fopen("spogulis.i2.txt", "r");
    // out = fopen("spogulis.out", "w+");
    // int node = 0;

    // fscanf(in, "%i", &node);
    // Ieejas failu vienmēr noslēdz rindiņa, kurā ir tikai skaitlis 0.
    // while (node == 0)
    // while (!feof(in))
    // {
        // fprintf(out, "%i\n", node);
        // fscanf(in, "%i", &node);
    // };

    ////////////////////////////////////////////////////////// implementation 2
    std::ifstream in("spogulis.in");
    std::ofstream out("spogulis.out");

    std::string line;
    int i;
    int n, sum;
    int node;
    while (std::getline(in, line))
    {
        std::string s = line;
        std::istringstream  is( s );
        // sum = 0;
        is >> node;
        out << node << " has: ";
        while( is >> n ) {
            // sum += n;
            out << n << " ";
        }
        // out << "sum is " << sum << "; ";

        // out << line << "\n";
        out << "\n";
    }

    // fclose(in);
    // fclose(out);
    return 0;
}