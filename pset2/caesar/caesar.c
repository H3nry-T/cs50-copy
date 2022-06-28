#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char c, int key);

int main(int argc, string argv[])
{

    // if the user does not give a argument OR gives too many arguments OR is NOT digit
    if (argc == 1 || argc > 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert the key given into an integer
    int keyasnumber = atoi(argv[1]);

    // prompt the user for a plain text
    string text = get_string("plaintext: ");

    // output the cipher text
    printf("ciphertext: ");

    // rotate the characters but do not change any punctuation
    for (int i = 0; i < strlen(text); i++)
    {
        char ciphertext = text[i];
        if (isalpha(ciphertext))
        {
            ciphertext = rotate(ciphertext, keyasnumber);
        }
        printf("%c", ciphertext);
        printf("\n");
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
            return false; // exit loop
        }
    }
    return true;
}

char rotate(char c, int key)
{
    char cipher = 0;
    if(isupper(c))
    {
        char alphaindex = c - 'A'; //alphaindex for A should be 0
        cipher = ((alphaindex + key) % 26) + 'A';
    }
    else if(islower(c))
    {
        char alphaindex = c - 'a'; // alphaindex for a should be 0
        cipher = ((alphaindex + key) % 26) + 'a';
    }
    return cipher;
}


// k (secret key) has to be a positive number
// preserve upper and lower case letters when printing ciphertext
// if k > 26 keep rotating through the ascii codes. so 27 more than A is B NOT [
