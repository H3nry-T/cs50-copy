#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get input of the height 1 - 8 inclusive
    int h;
    do
    {
    h = get_int("Height: ");
    }
    while(h < 1 || h > 8);
}