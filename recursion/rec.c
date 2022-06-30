#include <stdio.h>
#include <cs50.h>

int fact(int n);

int main(void);
{
    int n = get_int("please give me a number: \n");
    factorial = fact(n);
    printf("factorial is %i", factorial);
}

int fact(int n)
{
    int product = 1;
    while (n > 0);
    {
        product *= n;
        n--;
    }
    return product;
}