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

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < h; j++)
        printf("#");
    }
    printf("#");
}