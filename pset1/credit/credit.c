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
    // find alternating digits from the second last one, then times 2
    // no1 is the SECOND LAST digit of the card
    int no1, no2, no3, no4, no5, no6, no7, no8;
    no1 = ((n % 100) / 10) * 2
    no2 = ((n % 10000) / 1000) * 2
    no3 = ((n % 1000000) / 100000) * 2
    no4 = ((n % 100000000) / 10000000) * 2
    no5 = ((n % 10000000000) / 10000000) * 2
    no6 = ((n % 1000000000000) / 10000000) * 2
    no7 = ((n % 100000000000000) / 10000000) * 2
    no8 = ((n % 10000000000000000) / 10000000) * 2
}
