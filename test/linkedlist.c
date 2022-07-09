#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *nextnode;
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
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n -> number = 2;
    n -> nextnode = NULL;

    list -> nextnode = n;

    // add a number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list -> nextnode);
        free(list);
        return 1;
    }
    n -> number = 3;
    n -> nextnode = NULL;

    list -> nextnode -> nextnode = n;

    // print numbers imagine tmp = i, then it is similair to a normal for loop.
    for (node *tmp = list; tmp != NULL; tmp = tmp -> nextnode)
    {
        printf("%i\n", tmp -> number);
    }

    while (list != NULL)
    {
        node *tmp = list -> nextnode; //points to number 2
        free(list); //safely free address of number 1
        list = tmp; //list is now pointing at number 2

    }
}