#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
        printf("%i \n", n);
    }
    while (n < 1 || n > 8);


}