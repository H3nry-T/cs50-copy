#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool only_digits(char key);

int main(int argc, string argv[])
{

    // if the user does not give a argument or gives too many arguments
    if (argc == 1 || argc > 2 || only_digits(argv[1]) == 1)
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

bool only_digits(char key)
{
    if (isint(key))
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
