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
    cents

}