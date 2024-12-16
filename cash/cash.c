#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cash;
    do
    {
        cash = get_int("cash owed: ");
    }
    while (cash < 0);

    // calculating quarters
    int quarter = cash / 25;
    int remain = cash % 25;

    // calculating dimes
    int dime = remain / 10;
    remain = remain % 10;

    // calculating nickels
    int nickel = remain / 5;
    remain = remain % 5;

    // calculating pennies
    int penny = remain;

    // total of all the coins
    int coins = penny + nickel + dime + quarter;
    // printing the total number of coins
    printf("%i\n", coins);
}
