#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string str = get_string("input:  ");
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' || str[i] <= 'z')
        {
            printf("%c", str[i] - 32);
        }
        else
        {
            printf("%C", str[i]);
        }
    }
    printf("\n");
}
