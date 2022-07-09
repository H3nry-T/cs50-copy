#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    node *nextnode;
}
node;


int main(void)
{
    //create a node for my linked list
    node *list = NULL;

    //create  temporary node that is empty in RAM
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    //initialise our first node
    n -> number = 1;
    n -> nextnode = NULL;

    // update list to point to the temporary node

    list = n;

    //add a number to the list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n -> number = 2;
    n -> next = NULL;

    list -> next = n;
}