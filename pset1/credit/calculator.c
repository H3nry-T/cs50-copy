#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int no1 = 5111;
    int c = ((no1 % 100) / 10) * 2;
    int c2 = ((no1 % 10000)/ 1000 * 2);
    printf("%i and %i", c, c2);

}