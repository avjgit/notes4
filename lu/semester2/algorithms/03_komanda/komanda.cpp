#include "stdio.h"
#include "stdlib.h"

struct node
{
    long long self, left_nr, right_nr;
    node *next, *left, *right;
};

int main()
{
    FILE* in = fopen("komanda.in", "r");
    FILE* out = fopen("komanda.out", "w+");

    node* first = NULL;
    node* last = NULL;
    node* current = NULL;

    ///////////////////////////////////////////////// read input
    long long self, left, right;

    while (!feof(in))
    {
        fscanf  (in, "%lld %lld %lld", &self, &left, &right);

        current = new node;
        current->self           = self;
        current->left_nr        = left;
        current->right_nr       = right;
        current->next           = NULL;
        current->left           = NULL;
        current->right          = NULL;

        if (first == NULL)
        {
            first = current;
            last = current;
        }
        else
        {
            last->next = current;
            last = current;
        }
    }

    ///////////////////////////////////////////////// fill in childs and parent
    for(node *parent = first; parent != NULL; parent = parent->next)
    {
        // fprintf(stdout,"-------- in with parent %lld\n", parent->self);
        for(node *child = first; child != NULL; child = child->next)
        {
            // fprintf(stdout,"checking child %lld\n", child->self);
            if (child->self == parent->left_nr)
            {
                parent->left = child;
                break;
            }
        }

        if (parent->left == NULL)
        {
            current = new node;
            current->self           = parent->left_nr;
            current->left           = NULL;
            current->right          = NULL;
            parent->left = current;
        }

        for(node *child = first; child != NULL; child = child->next)
        {
            // fprintf(stdout,"checking child %lld\n", child->self);
            if (child->self == parent->right_nr)
            {
                parent->right = child;
                break;
            }
        }

        if (parent->right == NULL)
        {
            current = new node;
            current->self           = parent->right_nr;
            current->left           = NULL;
            current->right          = NULL;
            parent->right = current;
        }
    }

    node *maybe_parent = NULL;
    node *root = NULL;
    for(node *child = first; child != NULL; child = child->next)
    {
        // fprintf(stdout,"-------- in with child %lld\n", child->self);
        for(maybe_parent = first; maybe_parent != NULL; maybe_parent = maybe_parent->next)
        {
            // fprintf(stdout,"checking if parent %lld\n", maybe_parent->self);
            if (maybe_parent->left_nr  == child->self||
                maybe_parent->right_nr == child->self)
            {
                break;
            }
        }

        if (maybe_parent == NULL)
        {
            // fprintf(stdout, "inside root\n");
            root = child;
            break;
        }
    }
    // fprintf(stdout, "root is %lld\n", root->self);


    ///////////////////////////////////////////////// output
    node *left_node = NULL;
    node *right_node = NULL;
    long long left_node_self, right_node_self;

    for(current = first; current != NULL; current = current->next)
    {
        // fprintf(stdout, "current: %lld\n", current->self);

        left_node = current->left;
        left_node_self = left_node->self;

        right_node = current->right;
        right_node_self = right_node->self;

        fprintf(
            out,
            "%lld: %lld %lld\n",
            current->self,
            left_node_self,
            right_node_self
        );
    }

    ///////////////////////////////////////////////// closing
    fclose(in);
    fclose(out);
    return 0;
}