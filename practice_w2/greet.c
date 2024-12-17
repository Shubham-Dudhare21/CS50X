#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    printf("hello, ");
    for (int i = 0; i < argc-1; i++)
    {
        printf("%s", argv[i + 1]);
    }
    printf("\n");
}
