#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int change;
    do
    {
    change = get_int("Change owed: ");
    }
    while (change < 0 );
}