#include <stdio.h>
#include <cs50.h>

void pyramid(int height);

int main(void)
{
    int n = get_int("what is the height?: ");

}

void pyramid(int height)
{
    if (height == 0)
    {
        return 1;
    }
    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    pyramid(height - 1);
}