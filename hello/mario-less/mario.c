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

    for (int row = 0; row < h; row++)
    {
        // spacing is height - hashes. hashes = row + 1 (think about the base of the pyramid the row = 7 when 8 hashes + 1 to get 8. 8-8 = 0 so no spacing for the base.)
        for (int shift = 0; shift < h - row - 1; shift++)
        {
            printf(" ");
        }
        for (int column = 0; row >= column; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}