#include "stdio.h"
#include <conio.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
struct element{ int value; element *last_leaf, *siebling;};
element* exists(element *root, int element_value){
    if(root == NULL) {cout << "root is empty"; return root;};
    cout << "checking root " << root->value << "\n";
    // getch();

    if(root->value == element_value) return root;
    cout << "nope, not equal\n";
    if(root->last_leaf == NULL) return NULL;
    element* next = root->last_leaf;
    cout << "will check leaf " << next->value << "\n";

    element* in_subtree;
    while(next != NULL){

        cout << "checking leaf " << next->value << "\n";
        if(next->value == element_value) return next;
        in_subtree = exists(next, element_value);
        if((in_subtree != NULL) && (in_subtree->value == element_value)) return in_subtree;
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
        cout << "------------ took " << node_value << "\n";
        if (node_value == 0) break;
        if (root == NULL) {
            root = new element;
            root->value = node_value;
            root->last_leaf = NULL;
            root->siebling = NULL;
        }
        else{
            node = exists(root, node_value);
            if (node == NULL) {
                node = new element;
                node->value = node_value;
                node->last_leaf = NULL;
                node->siebling = NULL;
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
            current_leaf->last_leaf = NULL;
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
