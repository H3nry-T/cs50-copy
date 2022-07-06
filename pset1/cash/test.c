#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <getopt.h>
typedef char* string;



int main(void)
{
    char *argv[] = {"Hello", "Bob", "!"};
    char **argv;
    printf("%p\n", argv);
    printf("%p\n", argv[]);
    return 0;
}