#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool checkdupe(string key);
bool salphacheck(string key);

int main(int argc, string argv[])
{
    //single command line argument
    //case insensitive
    //if no argument or too many argument return 1;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        printf("you need to provide a key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("26 long alphabet needs to be provided\n");
    }
    if(salphacheck(argv[1]) == 0)
    {
        printf("key needs to be all alphabet\n");
    }
    if (checkdupe(argv[1]) == true)
    {
        printf("key needs to have 0 duplicates\n");
    }
    else
    {
        return 0;
    }
    //if key NOT 26 char, NOT alpha, NOT exactly 1 letter
    //ERROR
    //plaintext request
    //substitute each letter to the key
    //non alphabet should not be changed
    //preserve the case of each letter
    //cipher text output
    //new line, then return 0;
}

bool checkdupe(string key)
{
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
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