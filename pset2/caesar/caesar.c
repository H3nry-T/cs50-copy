#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool only_digits(string key);

int main(int argc, string argv[])
{

    // if the user does not give a argument OR gives too many arguments OR is NOT digit
    if (argc == 1 || argc > 2 || only_digits(argv[1]) != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return 0;
    }

    // convert the key given into an integer
    // prompt the user for a plain text
    // rotate the characters but do not change any punctuation
    // output the cipher text
}

bool only_digits(string key)
{
    //turn string into characters
    for (i = 0; i < strlen(key); i++)
    {
        digit[] = key[i]
    }
    if (isdigit() != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


// k (secret key) has to be a positive number
// preserve upper and lower case letters when printing ciphertext
// if k > 26 keep rotating through the ascii codes. so 27 more than A is B NOT [
