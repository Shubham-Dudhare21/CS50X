#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // input from the user
    string name = get_string("what's your name? ");

    // printing hello, name
    printf("Hello, %s\n", name);
}
