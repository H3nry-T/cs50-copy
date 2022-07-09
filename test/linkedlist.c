#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    node *pointer;
}
node;


int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    
}