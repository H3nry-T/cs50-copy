#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, i, j;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 0 || h > 8);

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < h; j++)
        {
            if (i + j < h - 1)
            {
                printf(".");
            }
            else
            {
                printf("#");
            }
    int k, m;
    for (k = 0; k < h; k++)
    {
        for (m = 0; m + j + 2 <= k + j; m++)
        {
            printf("#");
        }
    }
        }
        printf("  ");
        printf("\n");
    }

        printf("\n");
}