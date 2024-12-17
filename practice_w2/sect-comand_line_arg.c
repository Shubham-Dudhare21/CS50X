#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: no value for CL argument\n");
        return 0;
    }
    int x = atoi(argv[1]);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
