#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool checkdupe(string key);
bool salphacheck(string key);
char sub(string ptext, string key);
int main(int argc, string argv[])
{
    //single command line argument
    //case insensitive
    //if no argument or too many argument return 1;
    //if key NOT 26 char, NOT alpha, NOT exactly 1 letter
    //ERROR
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        printf("you need to provide a key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("26 long alphabet needs to be provided\n");
        return 1;
    }
    if(salphacheck(argv[1]) == 0)
    {
        printf("key needs to be all alphabet\n");
        return 1;
    }
    if (checkdupe(argv[1]) == true)
    {
        printf("there atleast 1 duplicated letter in your key\n");
        return 1;
    }
    //plaintext request
    string ptext = get_string("plaintext:");
    printf("ciphertext: ");
    //substitute each letter to the key
    //non alphabet should not be changed
    //preserve the case of each letter
    //cipher text output
    for (int i = 0; i < strlen(ptext); i++)
    {
        if (isalpha(ptext[i]))
        {
            ptext[i] = sub(ptext, argv[1]);
        }
        printf("%c", ptext[i]);
    }
    // printf("\n");
    return 0;
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
        if (isalpha(key[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

char sub(string ptext, string key) //take plaintext and key and output subbed character
{
    for (int i = 0; i < strlen(ptext); i++)
    {
        if(isupper(ptext[i])) //sub all uppercase characters with the key
        {
            int alphaindex = ptext[i] - 'A';//take uppercase character - 65
            for (int j = 0; j < 26; j++)
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

