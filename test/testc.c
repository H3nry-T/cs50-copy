#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("There must be 2 arguments \n");
        return 1;
    }

    int x = argv[1];
    printf("%i\n", &x);
    return 0;
}