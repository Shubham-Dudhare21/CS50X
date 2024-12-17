#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // start prompt
    int start;
    do
    {
        start = get_int("Start Size: ");
    }
    while (start < 9);

    // end prompt
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);

    // calculate years
    int years = 0;
    if (start == end)
    {
        years = 0;
    }
    else
    {
        while (start < end)
        {
            int born = start / 3;
            int death = start / 4;

            int growth = born - death;

            start = start + growth;

            years++;
        }
    }


    // print years
    printf("Years: %i\n", years);
}
