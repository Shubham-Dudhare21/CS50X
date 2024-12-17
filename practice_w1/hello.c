#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("enter name: ");
    printf("hello, %s!\n", name);
}
