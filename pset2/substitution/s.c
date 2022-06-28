#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

bool checkdupe(string argv[]);
bool salphacheck(string argv[]);

int main(int argc, string argv[])
{
    if (salphacheck(argv[1]) == 0|| checkdupe(argv[1]) == true)
    {
        prinf("error\n");
    }
}

bool checkdupe(string argv[])
{
    int len = strlen(argv[]);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                return true;
            }
        }
    }
    return false;
}

bool salphacheck(string argv[])
{
    for (i = 0; i < strlen(argv[]); i++)
    {
        if (isalpha(argv[][i]) == 0)
        {
            return false;
        }
    }
    return true;
}