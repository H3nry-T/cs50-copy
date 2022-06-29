#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool checkdupe(string key);
bool salphacheck(string key);
char sub(char ptext, string key);

int main(int argc, string argv[])
{
    if (salphacheck(argv[1]) == 0 || argc != 2 || strlen(argv[1]) != 26 || checkdupe(argv[1]) != 0)
    {
        printf("ERROR\n");
        
    }
    string ptext = get_string("plaintext:");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(ptext); i++)
    {
        char cipher = ptext[i];
        if (isalpha(ptext[i]))
        {
            cipher = sub(ptext[i], argv[1]);
        }
        printf("%c", cipher);
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
    char uletter = ptext;
    char lletter = ptext;

    if(isupper(ptext) != 0) //sub all uppercase characters with the key
    {
        int ualphaindex = uletter - 'A';//take uppercase character - 65
        uletter = toupper(key[ualphaindex]);
        return uletter;
    }
    else if (islower(ptext) != 0)// if lower case
    {
        int lalphaindex = lletter - 'a';//take lowercase character - '91'
        lletter = tolower(key[lalphaindex]);
        return lletter;
    }
    return 0; //exit function if not upper,lower case alphabet
}