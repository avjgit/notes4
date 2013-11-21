#include "stdio.h"
#include "stdlib.h"
//todo: remove
//#include <iostream>
//#include <fstream>
#include <fstream>
#include <string>
using namespace std;
//todo: end of remove

int main()
{
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

    std::ifstream in("spogulis.i7.txt");
    std::ofstream out("spogulis.out");
    std::string str;
    int i;
    while (std::getline(in, str))
    {
        out << str << "\n";
    }

    // fclose(in);
    // fclose(out);
    return 0;
}