#include <stdio.h>
typedef char* string;



int main(void)
{
    char *argv[] = {"Hello", "Bob", "!"};

    printf("%p\n", argv);
    printf("%p\n", argv[0]);
    return 0;
}