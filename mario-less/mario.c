#include <stdio.h>
// user made function
void print_row(int row, int space);
int get_int(char *message);

int main(void)
{
    // variable to take input from user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // loop to print pyramid
    for (int i = height; 0 < i; i--)
    {
        print_row(height - i + 1, i - 1);
    }
}

// function details
void print_row(int row, int space)
{
    // spaces before the symbol
    for (int i = space; i > 0; i--)
    {
        printf(" ");
    }
    // symbol row
    for (int i = 0; i < row; i++)
    {
        printf("#");
    }

    // to enter next line after the row
    printf("\n");
}

int get_int(char *message)
{
    printf("%s", message);
    int x;
    scanf("%d", &x);
    x = (int) x;
    return x;
}