#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool only_digits(string key);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    if (argc == 1 || only_digits(argv[1]))
    {
        printf("key is digits only key: %s\n", argv[1]);
    }
    else
    {
        printf("key has a non digit in it key: %s\n", argv[1]);
    }

    char cipher = rotate('A', 2);
    printf("%c\n", cipher);

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

char rotate(char c, int key)
{
    if(isupper(c))
    {
        char alphaindex = c - 'A'; //alphaindex for A should be 0
        char cipher = ((alphaindex + key) % 26) + 'A';
        return cipher;
    }
    else if(islower(c))
    {
        char alphaindex = c - 'a'; // alphaindex for a should be 0
        char cipher = ((alphaindex + key) % 26) + 'a';
        return cipher;
    }
}