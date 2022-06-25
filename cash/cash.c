#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //get the user to input the change owed
    float change;
    do
    {
    change = get_float("Change owed: ");
    }
    while (change < 0 );
}