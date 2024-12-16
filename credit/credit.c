#include <cs50.h>
#include <stdio.h>

void cardtype(long cardnumber);
bool checksum(long cardnumber);

int main(void)
{
    long cardnumber;
    do
    {
        cardnumber = get_long("Enter Your Card Number: ");
    }
    while (cardnumber < 0);

    if (checksum(cardnumber))
    {
        cardtype(cardnumber);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool checksum(long cardnumber)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;
    n1 = ((cardnumber % 10) / 1);
    n2 = ((cardnumber % 100) / 10) * 2;
    n3 = ((cardnumber % 1000) / 100);
    n4 = ((cardnumber % 10000) / 1000) * 2;
    n5 = ((cardnumber % 100000) / 10000);
    n6 = ((cardnumber % 1000000) / 100000) * 2;
    n7 = ((cardnumber % 10000000) / 1000000);
    n8 = ((cardnumber % 100000000) / 10000000) * 2;
    n9 = ((cardnumber % 1000000000) / 100000000);
    n10 = ((cardnumber % 10000000000) / 1000000000) * 2;
    n11 = ((cardnumber % 100000000000) / 10000000000);
    n12 = ((cardnumber % 1000000000000) / 100000000000) * 2;
    n13 = ((cardnumber % 10000000000000) / 1000000000000);
    n14 = ((cardnumber % 100000000000000) / 10000000000000) * 2;
    n15 = ((cardnumber % 1000000000000000) / 100000000000000);
    n16 = ((cardnumber % 10000000000000000) / 1000000000000000) * 2;

    n2 = (n2 % 100 / 10) + (n2 % 10);
    n4 = (n4 % 100 / 10) + (n4 % 10);
    n6 = (n6 % 100 / 10) + (n6 % 10);
    n8 = (n8 % 100 / 10) + (n8 % 10);
    n10 = (n10 % 100 / 10) + (n10 % 10);
    n12 = (n12 % 100 / 10) + (n12 % 10);
    n14 = (n14 % 100 / 10) + (n14 % 10);
    n16 = (n16 % 100 / 10) + (n16 % 10);

    int total =
        n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10 + n11 + n12 + n13 + n14 + n15 + n16;

    if ((total % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void cardtype(long cardnumber)
{
    int n13, n14, n15, n16;
    n13 = ((cardnumber % 10000000000000) / 1000000000000);
    n14 = ((cardnumber % 100000000000000) / 10000000000000);
    n15 = ((cardnumber % 1000000000000000) / 100000000000000);
    n16 = ((cardnumber % 10000000000000000) / 1000000000000000);

    long x = cardnumber;
    int len = 0;
    while (x > 0)
    {
        len++;
        x = x / 10;
    }

    if (len == 16 && n16 == 4)
    {
        printf("VISA\n");
    }
    else if (len == 13 && n13 == 4)
    {
        printf("VISA\n");
    }
    else if (len == 15 && n15 == 3 && (n14 == 4 || n14 == 7))
    {
        printf("AMEX\n");
    }
    else if (len == 16 && n16 == 5 && (n15 == 1 || n15 == 2 || n15 == 3 || n15 == 4 || n15 == 5))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
