#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    //ask how many cents the customer is owed
    int cents = get_cents("Change owed");

    //calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - no.quarters * 25;

    //calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    //calculate the number of pennies given to the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    //sum the coins
    int coins =  quarters + dimes + nickels + pennies ;

    //print the number of coins
    printf("%i ", coins);
}