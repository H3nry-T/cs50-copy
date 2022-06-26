#include <cs50.h>
#include <stdio.h>
#include <math.h>

//prototype for checking credit card number
bool checksum (int sum3);
int numlen(int card);
int startvisa(int card);

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
    no5 = ((n % 10000000000) / 10000000) * 2;
    no6 = ((n % 1000000000000) / 10000000) * 2;
    no7 = ((n % 100000000000000) / 10000000) * 2;
    no8 = ((n % 10000000000000000) / 10000000) * 2;

    int no9, no10, no11, no12, no13, no14, no15, no16;
    no9 = (n % 10);
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
    // check if the last digit of sum 3 is zero , then this is valid boolean expression true.

    if (checksum(sum3))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
//check the length of the card
    int length = numlen(n);
    printf("%i \n", length);

//check VISA
    if ((length == 16 || length == 13) && startvisa(n) == 4 ) // and starting digit is 4
    {
        printf("VISA \n");
    }
//check MASTERCARD 16 digits 51,52,53,54,55

//check AMERICAN EXPRESS 15 digits 34,37
}
bool checksum(int sum3)
{
    if (sum3 % 10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int numlen(int card)
{
    int length = 1;
    while (card >= 10)
    {
        card /= 10;
        length++;
    }
    return length;
}
// take starting digit (should be 4)
int startvisa(int card)
{
    while (card >= 10)
    {
        card /= 10;
    }
    return card;
}