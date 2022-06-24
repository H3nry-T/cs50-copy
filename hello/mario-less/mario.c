#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for(int row = n + 1; i > n; i--)
    {
        for(int column = 0; j < n; j++)
        printf("#");
        printf("\n");
    }
    printf("\n");
}