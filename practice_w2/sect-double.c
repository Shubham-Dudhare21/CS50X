#include <stdio.h>
#include <cs50.h>

int main()
{
    int x = get_int("Sequence length : ");
    int sequence[x];
    sequence[0] = 1;
    printf("%i ", sequence[0]);

    for (int i = 1; i < x; i++)
    {
        sequence[i] = sequence[i-1] * 2;
        printf("%i ", sequence[i]);
    }
    printf("\n");
}
