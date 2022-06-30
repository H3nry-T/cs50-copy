#include <stdio.h>
#include <cs50.h>

void pyramid(int height);

int main(void)
{
    int n = get_int("what is the height?: ");

}

void pyramid(int height)
{
    printf(height); 
    pyramid(height - 1);
}