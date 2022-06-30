#include <stdio.h>
#include <cs50.h>

void pyramid(int height);

int main(void)
{
    int n = get_int("what is the height?: ");

}

void pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i + 1)
        printf("\n");
    }
}