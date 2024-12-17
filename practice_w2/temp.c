#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_avg(int len, int array[]);

int main(void)
{
    int len = 3;
    int array[len];

    for (int i = 0; i < len; i++)
    {
        array[i] = get_int("score %i: ", i+1);
    }

    print_avg(len, array);
}

void print_avg(int len, int array[])
{
    int total = 0;
    for (int i = 0; i < len; i++)
    {
        total += array[i];
    }
    printf("avg: %f\n", total / (float) len);
}
