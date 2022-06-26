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
    while (n < 0);
    // in finding the second last digit, using the modulus of 100, this will get you the second last digit. 6872 / 100 = 68.72
    //take 72 and pick the first digit, of the remainder. which is the second last digit. (this REPEATS IN A PATTERN)
    
}
