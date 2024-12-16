#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes
bool check_arg(int a, string b[]);
void cipher(int a, string text);

int main(int argc, string argv[])
{
    // checking if the command line argument is valid
    if (check_arg(argc, argv))
    {
        printf("ERROR: \n");
        return 1;
    }

    // converting argv[1] to int
    int key = atoi(argv[1]);
    if (key > 26)
    {
        // rounding the key to get the number less than 26
        key %= 26;
    }

    // input for the plaintext
    string plaintext = get_string("plaintext:  ");

    // ciphering the text
    cipher(key, plaintext);
    return 0;
}

// function to check if the argument is correct
bool check_arg(int a, string b[])
{
    if (a != 2)
    {
        return true;
    }
    string str = b[1];
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            return true;
        }
    }
    return false;
}

// function to cipher the plaintext and print the ciphertext
void cipher(int a, string text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (islower(text[i]))
        {
            if (text[i] + a >= 122)
            {
                text[i] = ((text[i] + a) % 122) + 96;
            }
            else
            {
                text[i] = text[i] + a;
            }
        }
        else if (isupper(text[i]))
        {
            if (text[i] + a >= 90)
            {
                text[i] = ((text[i] + a) % 90) + 64;
            }
            else
            {
                text[i] = text[i] + a;
            }
        }
    }
    printf("ciphertext: %s\n", text);
}
