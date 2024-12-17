#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} record;

int main(void)
{
    int n = get_int("total persons: ");
    record person[n];

    for (int i = 0; i < n; i++)
    {
        person[i].name = get_string("name %i:", i+1);
        person[i].number = get_string("phone number %i:", i+1);
    }

    printf("name: %s\nnumber: %s", person[1].name, person[1].number);
    return 0;
}
