#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool checkdupe(string key);
bool salphacheck(string key);

int main(int argc, string argv[])
{
    if (salphacheck(argv[1]) == 0 || argc != 2 || strlen(argv[1]) != 26)
    {
        printf("key needs to be alphabet\n");
    }
    string ptext = get_string("plaintext:");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(ptext); i++)
    {
        if (isalpha(ptext[i]))
        {
            ptext[i] = sub(ptext, argv[1]);
        }
        printf("%c", ptext[i]);
    }
    printf("\n");
    return 0;
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
        if (isalpha(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

//debug
char sub(char ptext, string key) //take plaintext char and key and output subbed character
{
    string uletter = ptext;
    string lletter = ptext;

    if(isupper(ptext) != 0) //sub all uppercase characters with the key
    {
        int ualphaindex = uletter - 'A';//take uppercase character - 65
        uletter = key[ualphaindex];
        return uletter;
    }
    else if (islower(ptext[i]) != 0)// if lower case
    {
        int lalphaindex = lletter[i] - 'a';//take lowercase character - '91'
        uletter[i] = key[lalphaindex];
        return lletter[i];
    }

    return 0; //exit function if not upper,lower case alphabet
}