#include "stdio.h"
#include "stdlib.h"

struct node
{
    long long self, left_nr, right_nr;
    node *next, *previous, *left, *right;
};

class queue
{
private:
    node *first, *last, *dequeue, *empty;
public:
    queue()
    {
        empty = new node;
        empty->self = 0;
        empty->previous = NULL;

        first = empty;
        last = empty;

    }
    void in (node* node_in)
    {
        fprintf(stdout, "---------- in with %lld\n", node_in->self);
        // fprintf(stdout, "empty is %lld\n", empty->self);


        if (first->self == 0)
        {
            first = node_in;
            last = node_in;

            fprintf(stdout, "initializing first with %lld\n", first->self);
            fprintf(stdout, "initializing last with %lld\n", last->self);
        }
        else
        {
            fprintf(stdout, "last was %lld\n", last->self);
            fprintf(stdout, "first is %lld\n", first->self);

            last->previous = node_in;
            last = last->previous;

            fprintf(stdout, "now last is %lld\n", last->self);
            fprintf(stdout, "first is still %lld\n", first->self);
        }
    }
    node* out()
    {
        dequeue = first;

        fprintf(stdout, "dequeueing, first is %lld\n", first->self);
        fprintf(stdout, "dequeueing, last is %lld\n", last->self);
        fprintf(stdout, "dequeueing, %lld is to dequeue\n", dequeue->self);
        // fprintf(stdout, "dequeueing, empty is %lld\n", empty->self);

        // if (first->previous == NULL)
        if (first == last)
        {
            fprintf(stdout, "taking very last element\n");
            first = empty;
            last = empty;
        }
        else
        {
            fprintf(stdout, "taking %lld out of queue\n", first->self);
            first = first->previous;
        }

        fprintf(stdout, "after dequeueing, first is %lld\n", first->self);
        fprintf(stdout, "after dequeueing, last is %lld\n", last->self);
        fprintf(stdout, "dequeueing, %lld is to dequeue\n", dequeue->self);

        return dequeue;
    }
    bool is_empty()
    {
        if (first->self == 0)
        {
            fprintf(stdout, "queue is empty!\n");
            return true;
        }
        else
        {
            fprintf(stdout, "queue has: %lld\n", first->self);
            return false;
        }
    }
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
        current->previous      = NULL;
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

    ///////////////////////////////////////////////// traversal
    queue q;
    q.in(root);
    node *lefttest, *righttest;
    int test_i = 0;

    while (!q.is_empty() && test_i < 9)
    {
        fprintf(stdout, "######## loop starts\n");

        current = q.out();
        // if (test_i == 2) return 0;


        fprintf(stdout, "took: %lld\n", current->self);

        if (current->left != NULL){
            lefttest = current->left;
            fprintf(stdout, "enqueueing left, : %lld\n", lefttest->self);
            q.in(current->left);
        }
        if (current->right != NULL){
            righttest = current->right;
            fprintf(stdout, "enqueueing right, : %lld\n", righttest->self);
            q.in(current->right);
        }

        test_i++;
    }
    // return 0;

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

    // fprintf(
    //     out,
    //     "one more\n"
    // );

    // current = q.out();
    // fprintf(
    //     out,
    //     "%lld\n",
    //     current->self
    // );

    ///////////////////////////////////////////////// closing
    fclose(in);
    fclose(out);
    return 0;
}