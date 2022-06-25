#include <stdio.h>
#include <cs50.h>


int main(void)
{
// ask for a name
    string name = get_string("What is your name? \n");
//print the hello "name"
    printf("hello, %s \n", name);
}