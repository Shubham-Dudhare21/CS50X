// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool check[4] = {false};
    int len = strlen(password);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(password[i]))
        {
            check[0] = true;
        }
        else if (isupper(password[i]))
        {
            check[1] = true;
        }
        else if (islower(password[i]))
        {
            check[2] = true;
        }
        else
        {
            check[3] = true;
        }
    }
    if (check[0] && check[1] && check[2] && check[3])
    {
        return true;
    }
    return false;
}
