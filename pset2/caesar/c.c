#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("argv[last] is %s\n", argv[argc - 1]);
    printf("argv[first] is %s\n", argv[1]);
}
// take in a command line argument for a key
// if the user does not give a number
// if the user does not give a argument
// if the user gives multiple arguments
//print the Usage: ./caesar key
// k (secret key) has to be a positive number
// preserve upper and lower case letters when printing ciphertext