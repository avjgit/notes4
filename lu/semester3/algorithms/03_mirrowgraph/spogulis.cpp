#include "stdio.h"
#include "stdlib.h"

#include <fstream>
#include <sstream>
using namespace std;
struct element
{
    int value;
    element *last_leaf, *siebling;
};
int main(){
    ifstream in("spogulis.in");
    ofstream out("spogulis.out");
    string line;
    int node, leaf;
    element *root = NULL;
    element *current = NULL;
    element *previous = NULL;


    while (getline(in, line)){
        istringstream linestream(line);
        linestream >> node;
        if (root == NULL) {
            root = new element;
            root->value = node;
        }
        else{

        }
        // out << node_value << " ";
        while( linestream >> leaf ) {
            // out << leaf << " ";
            current = new element;
            current->value = leaf;

        }

        // out << "\n";
    }
    return 0;
}
