// valid triangle practice problem.
#include <stdio.h>
#include <cs50.h>

bool val_tri(float a, float b, float c);

int main(void)
{
    float a = get_float("Enter A: ");
    float b = get_float("Enter B: ");
    float c = get_float("Enter C: ");
    if (val_tri(a, b, c))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}


bool val_tri(float a, float b, float c)
{
    if (a+b <= c || b+c <= a || a+c <= b)
    {
        return false;
    }
    else if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
