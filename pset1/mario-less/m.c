#include <stdio.h>
#include <cs50.h>

void pyramid(int height);

int main(void)
{
    int n = get_int("what is the height?: ");
    pyramid(n);
}

void pyramid(int n)
{
    if (n <= 0)
    {
        return;
    }
    pyramid(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

