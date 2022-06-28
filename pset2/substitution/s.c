#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool checkdupe(string key);
bool salphacheck(string key);

int main(int argc, string argv[])
{
    if (argv[1] != 2 || salphacheck(argv[1]) == 0 || checkdupe(argv[1]) == true)
    {
        printf("Usage: ./substitution key\n");
        printf("key needs to be 26 long alphabet")
    }
}

bool checkdupe(string key)
{
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (key[i] == key[j])
            {
                return true;
            }
        }
    }
    return false;
}

bool salphacheck(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[1]) == 0)
        {
            return false;
        }
    }
    return true;
}