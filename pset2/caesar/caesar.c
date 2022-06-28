#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // take in a command line argument for a key
    // if the user does not give a number
    // if the user does not give a argument
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // if the user gives multiple arguments
    else if(argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //print the Usage: ./caesar key
    // convert the key given into an integer
    // prompt the user for a plain text
    // rotate the characters but do not change any punctuation
    // output the cipher text
}
// take in a command line argument for a key
// if the user does not give a number
// if the user does not give a argument
// if the user gives multiple arguments
//print the Usage: ./caesar key
// k (secret key) has to be a positive number
// preserve upper and lower case letters when printing ciphertext
// if k > 26 keep rotating through the ascii codes. so 27 more than A is B NOT [
