// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input, int len);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ");
        return 1;
    }
    int len = strlen(argv[1]);

    printf("%s\n", replace(argv[1], len));
}

string replace(string input, int len)
{
    string output = input;
    for (int i = 0; i < len; i++)
    {
        switch(input[i])
        {
            case 'a' :
                output[i] = '6';
                break;
            case 'e' :
                output[i] = '3';
                break;
            case 'i' :
                output[i] = '1';
                break;
            case 'o' :
                output[i] = '0';
                break;
            default:
                output[i] = input[i];
        }
    }
    return output;
}
