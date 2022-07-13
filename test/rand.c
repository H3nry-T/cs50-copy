#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char random_allele();

int main(void)
{
    srand(time(0));

    for (int i = 0; i < 10; i ++)
    {
        char c = random_allele();
        printf("%c", c);
    }

    printf("\n");

    for (int i = 0; i < 10; i ++)
    {
        int r = rand() % 3;
        printf("%i", r);
    }

    printf("\n");

}

char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else if (r == 2)
    {
        return 'O';
    }
}