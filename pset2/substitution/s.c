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
    string uletter = ptext
    string lletter = ptext
    for (int i = 0; i < strlen(ptext); i++) //loop through ptext
    {
        if(isupper(ptext[i])) //sub all uppercase characters with the key
        {
            int ualphaindex = uletter[i] - 'A';//take uppercase character - 65
            uletter[i] = key[ualphaindex];
            return uletter[i];
        }
        else if (islower(ptext[i]))// if lower case
        {
            int lalphaindex = lletter[i] - 'a';//lowercase letter - 91
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