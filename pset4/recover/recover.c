#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("only accepts one command-line argument\n");
        printf("Correct usage: <name of forensic image> \n");
        return 1;
    }
    FILE *f = fopen(filename, "r"); //get the file pointer which is the memory address of the opened image.
    if (f == NULL)
    {
        printf("the file does not exist\n");
        return 1;
    }
    fread()
}