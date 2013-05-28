// Andrejs Jurcenoks
// aj05044
// Datu strukturas un pamatalgoritmi I
// PD2
// https://github.com/avjgit/notes4/tree/master/lu/semester2/algorithms/03_komanda
#include "stdio.h"
#include "stdlib.h"

struct node
{
    long long self, left_nr, right_nr, level;
    node *next, *previous, *left, *right;
    node *tree_stack_next, *level_stack_next;
};

class t_stack
{
private:
    node *last, *outstack, *empty;
public:
    t_stack()
    {
        empty = new node;
        empty->self = 0;
        empty->tree_stack_next = NULL;
        empty->level_stack_next = NULL;

        last = empty;
        outstack = empty;
    }
    void put(node* node_in)
    {
        node_in->tree_stack_next = last;
        last = node_in;
        // last->tree_stack_next = empty;
    }
    node* pop()
    {
        outstack = last;
        last = last->tree_stack_next;
        return outstack;
    }
    bool is_empty()
    {
        return last->tree_stack_next == NULL;
    }

};


class l_stack
{
private:
    node *last, *outstack, *empty;
public:
    l_stack()
    {
        empty = new node;
        empty->self = 0;
        empty->tree_stack_next = NULL;
        empty->level_stack_next = NULL;

        last = empty;
        outstack = empty;
    }
    void put(node* node_in)
    {
        node_in->level_stack_next = last;
        last = node_in;
    }
    node* pop()
    {
        outstack = last;
        last = last->level_stack_next;
        return outstack;
    }
    bool is_empty()
    {
        return last->level_stack_next == NULL;
    }

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
        // fprintf(stdout, "---------- in with %lld\n", node_in->self);
        // fprintf(stdout, "empty is %lld\n", empty->self);
        if (first->self == 0)
        {
            first = node_in;
            last = node_in;

            // fprintf(stdout, "initializing first with %lld\n", first->self);
            // fprintf(stdout, "initializing last with %lld\n", last->self);
        }
        else
        {
            // fprintf(stdout, "last was %lld\n", last->self);
            // fprintf(stdout, "first is %lld\n", first->self);

            last->previous = node_in;
            last = last->previous;

            // fprintf(stdout, "now last is %lld\n", last->self);
            // fprintf(stdout, "first is still %lld\n", first->self);
        }
    }
    node* out()
    {
        dequeue = first;

        // fprintf(stdout, "dequeueing, first is %lld\n", first->self);
        // fprintf(stdout, "dequeueing, last is %lld\n", last->self);
        // fprintf(stdout, "dequeueing, %lld is to dequeue\n", dequeue->self);
        // fprintf(stdout, "dequeueing, empty is %lld\n", empty->self);

        // if (first->previous == NULL)
        if (first == last)
        {
            // fprintf(stdout, "taking very last element\n");
            first = empty;
            last = empty;
        }
        else
        {
            // fprintf(stdout, "taking %lld out of queue\n", first->self);
            first = first->previous;
        }

        // fprintf(stdout, "after dequeueing, first is %lld\n", first->self);
        // fprintf(stdout, "after dequeueing, last is %lld\n", last->self);
        // fprintf(stdout, "dequeueing, %lld is to dequeue\n", dequeue->self);

        return dequeue;
    }
    bool is_empty()
    {
        if (first->self == 0)
        {
            // fprintf(stdout, "queue is empty!\n");
            return true;
        }
        else
        {
            // fprintf(stdout, "queue has: %lld\n", first->self);
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

        if (self == 0)
        {
            break;
        }

        current = new node;
        current->self           = self;
        current->left_nr        = left;
        current->right_nr       = right;
        current->next           = NULL;
        current->previous       = NULL;
        current->left           = NULL;
        current->right          = NULL;
        current->level          = -1;
        current->tree_stack_next = NULL;
        current->level_stack_next = NULL;

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
        // fprintf(stdout,"left is %lld\n", parent->left_nr);
        // fprintf(stdout,"right is %lld\n", parent->right_nr);

        if (parent->left_nr != 0)
        {
            for(node *child = first; child != NULL; child = child->next)
            {
                // fprintf(stdout,"checking child for left: %lld\n", child->self);
                if (child->self == parent->left_nr)
                {
                    // fprintf(stdout,"found!\n");
                    parent->left = child;
                    break;
                }
            }
        }

        // if (parent->left == NULL)
        // {
        //     current = new node;
        //     current->self           = parent->left_nr;
        //     current->left           = NULL;
        //     current->right          = NULL;
        //     parent->left = current;
        // }

        if (parent->right_nr != 0)
        {
            for(node *child = first; child != NULL; child = child->next)
            {
                // fprintf(stdout,"checking child for right: %lld\n", child->self);
                if (child->self == parent->right_nr)
                {
                    // fprintf(stdout,"found!\n");
                    parent->right = child;
                    break;
                }
            }
        }

        // if (parent->right == NULL)
        // {
        //     current = new node;
        //     current->self           = parent->right_nr;
        //     current->left           = NULL;
        //     current->right          = NULL;
        //     parent->right = current;
        // }
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
    t_stack tree_stack;

    root->level = 0;
    q.in(root);

    node *lefttest, *righttest;

    while (!q.is_empty())
    {
        // fprintf(stdout, "######## loop starts\n");

        current = q.out();

        // fprintf(stdout, "took: %lld\n", current->self);
        tree_stack.put(current);

        if (current->left != NULL){
            // fprintf(stdout, "enqueueing left, : %lld\n", lefttest->self);
            lefttest = current->left;
            lefttest->level = current->level + 1;
            q.in(current->left);
        }
        if (current->right != NULL){
            // fprintf(stdout, "enqueueing right, : %lld\n", righttest->self);
            righttest = current->right;
            righttest->level = current->level + 1;
            q.in(current->right);
        }

    }
    // return 0;

    ///////////////////////////////////////////////// output
    // node *left_node = NULL;
    // node *right_node = NULL;
    // long long left_node_self, right_node_self;


    // testoutput1 - just list
    // for(current = first; current != NULL; current = current->next)
    // {
    //     // fprintf(stdout, "current: %lld\n", current->self);

    //     left_node = current->left;
    //     left_node_self = left_node->self;

    //     right_node = current->right;
    //     right_node_self = right_node->self;

    //     fprintf(
    //         out,
    //         "%lld: %lld %lld\n",
    //         current->self,
    //         left_node_self,
    //         right_node_self
    //     );
    // }

    //testoutput2 - levels
    // while (!tree_stack.is_empty())
    // {
    //     current = tree_stack.pop();
    //     fprintf(out, "%lld: %lld\n", current->level, current->self);
    // }


    // real output

    node *levelnode;
    l_stack level_stack;
    current = tree_stack.pop();
    long long cur_level = current->level;
    // fprintf(stdout, "poped level %lld: %lld\n", current->level, current->self);
    level_stack.put(current);

    while (!tree_stack.is_empty())
    {
        current = tree_stack.pop();
        // fprintf(stdout, "poped level %lld: %lld\n", current->level, current->self);

        // loading stack until next level pops up
        if (current->level == cur_level)
        {
            level_stack.put(current);
            // fprintf(stdout, "same level, put to stack\n");
        }
        // when new level pops up, then load the level stack to file
        else
        {
            // fprintf(stdout, "we have new level!\n");
            fprintf(out, "%lld:", cur_level);
            cur_level = current->level;

            while (!level_stack.is_empty())
            {
                levelnode = level_stack.pop();
                fprintf(out, " %lld", levelnode->self);
            }
            fprintf(out, "\n");

            level_stack.put(current);
        }
    }

    fprintf(out, "%lld:", cur_level);

    while (!level_stack.is_empty())
    {
        levelnode = level_stack.pop();
        fprintf(out, " %lld", levelnode->self);
    }
    fprintf(out, "\n");

    ///////////////////////////////////////////////// closing
    // fprintf(stdout,"done\n");
    fclose(in);
    fclose(out);
    return 0;
}
