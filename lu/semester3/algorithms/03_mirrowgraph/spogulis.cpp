#include "stdio.h"
// #include "stdlib.h"
//todo: remove
// #include <iostream>
#include <fstream>
// #include <string>
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
    // fclose(in);
    // fclose(out);
    ////////////////////////////////////////////////////////// implementation 2
    ifstream in("spogulis.in");
    ofstream out("spogulis.out");
    string line;
    int leaf, node;
    while (getline(in, line))
    {
        istringstream linestream(line);
        linestream >> node;
        out << node << " has: ";
        while( linestream >> leaf ) {
            out << leaf << " ";
        }
        out << "\n";
    }

    fprintf(stdout, "Sis kods veiksmigi kompilejas. Pedejais mezgls bija %i\n", node);

    return 0;
}