#include "stdio.h"
#include "stdlib.h"

struct node
{
    long long self, left_nr, right_nr;
    node *next, *parent, *left, *right;
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
    // for(node *parent = first; parent != NULL; parent = parent->next)
    // {
    //     for(node *child = first->next; child != NULL; child = child->next)
    //     {
    //         if (child->self = parent->left_nr)
    //         {
    //             parent->left = child;
    //             break;
    //         }
    //         if (child->self = parent->right_nr)
    //         {
    //             parent->right = child;
    //             break;
    //         }
    //     }
    // }

    // node *maybe_parent = NULL;
    // node *root = NULL;
    // for(node *child = first; child != NULL; child = child->next)
    // {
    //     for(maybe_parent = first->next; maybe_parent != NULL; maybe_parent = maybe_parent->next)
    //     {
    //         if (maybe_parent->left_nr  == child->self||
    //             maybe_parent->right_nr == child->self)
    //         {
    //             break;
    //         }
    //     }
    //     if (maybe_parent = NULL)
    //     {
    //         root = child;
    //         break;
    //     }
    // }

    ///////////////////////////////////////////////// output
    for(current = first; current != NULL; current = current->next)
    {
        fprintf (
            out,
            "%lld: %lld %lld\n",
            current->self,
            current->left_nr,
            current->right_nr);
    }

    ///////////////////////////////////////////////// closing
    fclose(in);
    fclose(out);
    return 0;
}