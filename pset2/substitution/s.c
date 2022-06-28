#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool checkdupe(string key);
bool salphacheck(string key);

int main(int argc, string argv[])
{
    if (salphacheck(argv[1]) == 0)
    {
        printf("key needs to be alphabet\n");
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
        if (isalpha(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

//debug
char sub(string ptext, string key) //take plaintext and key and output subbed character
{
    for (int i = 0; i < strlen(ptext); i++) //loop through ptext
    {
        if(isupper(ptext[i])) //sub all uppercase characters with the key
        {
            int alphaindex = ptext[i] - 'A';//take uppercase character - 65
            for (int j = 0; j < 27; j++) // HERE DOWN REPLACE
            {
                if(alphaindex == j)//compare the keyindex (j) to the uppercase letter
                {
                    ptext[i] = key[j];//replace e.g letter A with key[0]
                    return ptext[i];
                }
            }
        }
        else if (islower(ptext[i]))// if lower case
        {
            int alphaindex = ptext[i] - 'a';//lowercase letter - 91
            for (int j = 0; j < 26; j++)
            {
                if(alphaindex == j)//compare keyindex (j) to the lowercase letter
                {
                    ptext[i] = key[j];//replace e.g letter a with key[0]
                    return ptext[i];
                }
            }
        }
    }
    return 0; //exit function if not upper,lower case alphabet
}

//replace with

ptext[i] = key[alphaindex]