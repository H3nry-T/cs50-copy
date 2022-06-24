#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for(int row = 0; row < h; row++)
    {
        for (shift = 0; )
        for(int column = 0; row >= column; column++)
        {
        printf("#");
        }
        printf("\n");
    }
}