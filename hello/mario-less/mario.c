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

    for(int i = n + 1; i > n; i--)
    {
        for(int j = 0; j < n; j++)
        printf("#");
        printf("\n");
    }
    printf("\n");
}