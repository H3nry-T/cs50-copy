#include <cs50.h>
#include <stdio.h>
#include <math.h>

//prototype for checking credit card number
bool checksum (int number);

int main(void)
{
    long n;
    do
    {
    n = get_long("Number; ");

    }
    while (n < 0) //card number cannot be negative
}
