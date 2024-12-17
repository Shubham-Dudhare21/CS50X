#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string str = get_string("input: ");
    for (int i = 0, a = strlen(str); i < a; i++)
    {
        str[i] = toupper(str[i]);
    }
    printf("output: %s\n", str);
}
