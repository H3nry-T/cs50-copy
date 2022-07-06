#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <getopt.h>
typedef char* string;



int main(void)
{
    char *s = "Hello World!";
    char *t[] = {0,1,2,3,4,5};
    printf("%p\n", s);
    printf("%p\n", t[]);
    return 0;
}