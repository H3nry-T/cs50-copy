#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("There must be 2 arguments \n");
        return 1;
    }

    
    int x = atoi(argv[1]);
    printf("%i\n", x);
    return 0;
}