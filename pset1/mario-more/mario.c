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

    for (i = 0; i < h; i++);
    {
        for (j = 0; j < h; i++);
        {
            printf("# \n"); 
        }
    }
}