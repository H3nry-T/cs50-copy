#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n = get_int("pls give integer: ");
    if (n < 0)
    {
        return 1;
    }
    else
    {
        int x = collatz(n);
        printf("steps taken: %i\n", x);
    }
}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if ((n % 2) == 0)
    {
        return 1 + collatz(n/2);
    }
    else
    {
        return 1 + collatz(3 * n + 1);
    }
}