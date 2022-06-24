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
        for (int shift = 0; shift < h - row - 1; shift++)
        {
            printf("~");
        }
        for(int column = 0; row >= column; column++)
        {
        printf("#");
        }
        printf("\n");
    }
}