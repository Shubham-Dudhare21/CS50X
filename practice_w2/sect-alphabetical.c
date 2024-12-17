#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string a = get_string("Enter the phrase: ");
    for (int i = 0, j = strlen(a); i < j-1; i++)
    {
        if (a[i] > a[i+1])
        {
            printf("The phrase is not in alphabetical order!\n");
            return 0;
        }
    }
    printf("The phrase is in alphabatical order!\n");
    return 0;
}
