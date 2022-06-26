#include <cs50.h>
#include <stdio.h>
#include <math.h>

//prototype for checking credit card number
bool checksum (int sum3);
int numlen(long card);
int startvisa(long visa);
int startmaster(long master);
int startamex(long amex);

int main(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);
    // find alternating digits from the second last one, then times 2
    // no1 is the SECOND LAST digit of the card
    int no1, no2, no3, no4, no5, no6, no7, no8;
    no1 = ((n % 100) / 10) * 2;
    no2 = ((n % 10000) / 1000) * 2;
    no3 = ((n % 1000000) / 100000) * 2;
    no4 = ((n % 100000000) / 10000000) * 2;
    no5 = ((n % 10000000000) / 1000000000) * 2;
    no6 = ((n % 1000000000000) / 100000000000) * 2;
    no7 = ((n % 100000000000000) / 10000000000000) * 2;
    no8 = ((n % 10000000000000000) / 1000000000000000) * 2;

    no1 = (no1 % 100 / 10) + (no1 % 10);
    no2 = (no2 % 100 / 10) + (no2 % 10);
    no3 = (no3 % 100 / 10) + (no3 % 10);
    no4 = (no4 % 100 / 10) + (no4 % 10);
    no5 = (no5 % 100 / 10) + (no5 % 10);
    no6 = (no6 % 100 / 10) + (no6 % 10);
    no7 = (no7 % 100 / 10) + (no7 % 10);
    no8 = (no8 % 100 / 10) + (no8 % 10);

    int no9, no10, no11, no12, no13, no14, no15, no16;
    no9  = (n % 10);
    no10 = (n % 1000) / 10;
    no11 = (n % 100000) / 1000;
    no12 = (n % 10000000) / 100000;
    no13 = (n % 1000000000) / 10000000;
    no14 = (n % 100000000000) / 1000000000;
    no15 = (n % 10000000000000) / 100000000000;
    no16 = (n % 1000000000000000) / 10000000000000;

    int sum1 = no1 + no2 + no3 + no4 + no5 + no6 + no7 + no8;
    int sum2 = no9 + no10 + no11 + no12 + no13 + no14 + no15 + no16;
    int sum3 = sum1 + sum2;

    int length = 0
    while (n > 0)
    {
        n /= 10
        length++;
    }

    if (sum3 % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long visa = n
    long amex = n
    long master = n

    while (visa >= 10)
    {
        visa /= 10
    }

    else if ((length == 16 || length = 13) && visa == 4 )
    {
        printf("VISA\n");
        return 0;
    }
}