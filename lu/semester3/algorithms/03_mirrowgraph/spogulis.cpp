// Andrejs Jurcenoks
// aj05044
// Datu strukturas un pamatalgoritmi II
// PD3 Spogulis
// https://github.com/avjgit/notes4/blob/master/lu/semester3/algorithms/03_mirrowgraph/spogulis.cpp
#include <fstream>
#include <sstream>
using namespace std;

struct element{int value; element *last_leaf, *siebling;};

element* referenced_as_leaf(element *last_node, int target)
{   //finds, if target is mentioned somewhere as leaf
    element *node = last_node;
    element *leaf = NULL;
    // looping through all nodes
    while(node != NULL){
        leaf = node->last_leaf;
        // looping through all leaves of a node
        while(leaf != NULL){
            if(leaf->value == target) return leaf;
            leaf = leaf->siebling;
        }
        node = node->siebling;
    }
    return NULL;
}

void print(ofstream& file, element *root){
    if (root == NULL) return;
    // 1st: prints root itself
    file << root->value << " ";
    // 2nd: prints all root's leaves, starting from last
    element *next = root->last_leaf;
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
    int node_value, leaf_value;
    int FLAG_STOP = 0;
    element *root = NULL;
    element *node = NULL;
    element *current_leaf = NULL;
    element *previous_leaf = NULL;
    element *previous_node = NULL;

    while (getline(in, line)){
        istringstream linestream(line);
        linestream >> node_value;
        // cout << "------------ took " << node_value << "\n";
        if (node_value == FLAG_STOP) break;

        node = new element;
        node->value = node_value;
        node->last_leaf = NULL;
        node->siebling = previous_node;
        previous_node = node;

        while( linestream >> leaf_value ) {
            current_leaf = new element;
            current_leaf->value = leaf_value;
            current_leaf->siebling = previous_leaf;
            current_leaf->last_leaf = NULL;
            previous_leaf = current_leaf;
        }

        node->last_leaf = previous_leaf;
        previous_leaf = NULL;
    }

    element *node_to_check = node;
    element *referenced = NULL;
    while(node_to_check != NULL){
        referenced = referenced_as_leaf(previous_node, node_to_check->value);
        if (referenced == NULL){
            root = node_to_check;
        }
        else{
            referenced->last_leaf = node_to_check->last_leaf;
        }
        node_to_check = node_to_check->siebling;
    }

    print(out, root);
    out << FLAG_STOP;
    return 0;
}
