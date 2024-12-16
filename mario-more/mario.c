#include <cs50.h>
#include <stdio.h>

// User defined function
void rows(int spaces, int tags);
void bricks(int tags);

int main(void)
{
    // height input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // printing column
    for (int i = 0; i < height; i++)
    {
        // using fuction to print row
        rows(height - i - 1, i + 1);
    }
}

// function to print row
void rows(int spaces, int tags)
{
    // spaces printing
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    // printing tags row with function called brick
    bricks(tags);
    printf("  ");
    bricks(tags);
    printf("\n");
}

// function to print tags
void bricks(int tags)
{
    for (int i = 0; i < tags; i++)
    {
        printf("#");
    }
}
