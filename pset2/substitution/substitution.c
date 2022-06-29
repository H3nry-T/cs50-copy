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
        char cipher = ptext[i];
        if (isalpha(ptext[i]))
        {
            cipher = sub(ptext[i], argv[1]);
        }
        printf("%c", cipher);
    }
    printf("\n");
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
