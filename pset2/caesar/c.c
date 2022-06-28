#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool only_digits(string key);

int main(int argc, string argv[])
{
    if (only_digits(argv[1]))
    {
        printf("key is digits only\n");
    }
    else
    {
        printf("key has a non digit in it\n");
    }
}

bool only_digits(string key) // if key = 20x this should return false
{
    //turn string into characters
    int i = 0;
    while(i < strlen(key))
    {
        if (isdigit(key[i]) != 0) // if char is digit
        {
            i++;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}