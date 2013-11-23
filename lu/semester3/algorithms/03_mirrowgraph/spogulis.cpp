// Andrejs Jurcenoks
// aj05044
// Datu strukturas un pamatalgoritmi II
// PD3 Spogulis
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/03_mirrowgraph/spogulis.cpp
#include <fstream>
#include <sstream>
using namespace std;

struct element{int value; element *last_leaf, *siebling;};

element* referenced_as_leaf(element* last_node, int target)
{   //this function finds, if target is mentioned somewhere as leaf
    element* node = last_node;
    element* leaf = NULL;

    // looping through all nodes
    while(node != NULL){

        // looping through all leaves of a node
        leaf = node->last_leaf;
        while(leaf != NULL){
            if(leaf->value == target) return leaf;
            leaf = leaf->siebling;
        }
        node = node->siebling;
    }
    return NULL;
}

void print(ofstream& file, element* root){
    if (root == NULL) return;
    // 1st: prints root itself
    file << root->value << " ";
    // 2nd: prints all root's leaves, starting from last
    element* next = root->last_leaf;
    while(next != NULL){
        file << next->value << " ";
        next = next->siebling;
    }
    file << "\n";
    // 3rd: for each leaf, prints it's leaves
    next = root->last_leaf;
    while(next != NULL){
        if (next->last_leaf != NULL) print(file, next);
        next = next->siebling;
    }
}

int main(){
    ifstream in("spogulis.in");
    ofstream out("spogulis.out");
    string line;
    int node_value, leaf_value, FLAG_STOP = 0;
    element* root = NULL;
    element* node = NULL;
    element* leaf = NULL;
    element* last_leaf = NULL;
    element* last_node = NULL;

    while (getline(in, line)){
        istringstream linestream(line);
        linestream >> node_value;
        if (node_value == FLAG_STOP) break;

        node = new element;
        node->value = node_value;
        node->siebling = last_node;
        last_node = node;

        while( linestream >> leaf_value ) {
            leaf = new element;
            leaf->last_leaf = NULL; //important!
            leaf->value = leaf_value;
            leaf->siebling = last_leaf;
            last_leaf = leaf;
        }

        node->last_leaf = last_leaf;
        last_leaf = NULL;
    }

    element* node_to_check = last_node;
    element* reference_as_leaf = NULL;
    while(node_to_check != NULL){
        reference_as_leaf = referenced_as_leaf(last_node, node_to_check->value);
        if (reference_as_leaf == NULL){
            root = node_to_check;
        }
        else{
            reference_as_leaf->last_leaf = node_to_check->last_leaf;
        }
        node_to_check = node_to_check->siebling;
    }

    print(out, root);
    out << FLAG_STOP;
    return 0;
}
