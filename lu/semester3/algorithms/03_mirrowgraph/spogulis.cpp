#include "stdio.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
struct element{ int value; element *last_leaf, *siebling;};
element* exists(element *root, int element_value){

    if(root->value == element_value) return root;
    element* next = root->last_leaf;
    element* in_subtree;
    while(next != NULL){
        if(next->value == element_value) return next;
        // in_subtree = exists(next, element_value);
        // if(in_subtree->value == element_value) return in_subtree;
        next = next->siebling;
    }
    return NULL;
}
int main(){
    ifstream in("spogulis.in");
    ofstream out("spogulis.out");
    string line;
    int node_value, leaf_value;
    element *root = NULL;
    element *node = NULL;
    element *current_leaf = NULL;
    element *previous_leaf = NULL;


    while (getline(in, line)){
        istringstream linestream(line);
        linestream >> node_value;
        if (root == NULL) {
            root = new element;
            root->value = node_value;
        }
        else{
            node = exists(root, node_value);
            if (node == NULL) {
                node = new element;
                node->value = node_value;
            }
            else{
                cout << "ok, found " << node->value << "\n";
            }
        }
        // out << node_value_value << " ";
        while( linestream >> leaf_value ) {
            // out << leaf_value << " ";
            current_leaf = new element;
            current_leaf->value = leaf_value;
            current_leaf->siebling = previous_leaf;
            previous_leaf = current_leaf;
        }

        if (node == NULL) {
            root->last_leaf = previous_leaf;
        }
        else{
            node->last_leaf = previous_leaf;
        }

        previous_leaf = NULL;

        // out << "\n";
    }
    return 0;
}
