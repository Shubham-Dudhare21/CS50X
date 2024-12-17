#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR\n");
        return 1;
        //check the return value with 'echo $?' after runing the code
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
