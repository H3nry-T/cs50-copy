#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //single command line argument
    //case insensitive
    //if no argument or too many argument return 1;
    if (int argc != 2 || strlen(argv[1]) != 26 || isalpha(argv[1]) == false || )
    {
        printf("ERROR\n");
        return 1;
    }
    //if key NOT 26 char, NOT alpha, NOT exactly 1 letter
    //ERROR
    //plaintext request
    //substitute each letter to the key
    //non alphabet should not be changed
    //preserve the case of each letter
    //cipher text output
    //new line, then return 0;
}