#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variable key
char key[26];

// prototypes of the functions
bool key_validation(string k);
void cipher(string pt, int l);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR: SUBSTITUTION KEY MISSING!\n");
        return 1;
    }

    // key assignment and validation
    if (key_validation(argv[1]))
    {
        return 1;
    }

    // getting the user input for plaintext
    string plaintext = get_string("plaintext:  ");
    int ptlen = strlen(plaintext);

    // ciphering the plaintext
    cipher(plaintext, ptlen);

    return 0;
}

bool key_validation(string k)
{
    // checking if the key is 26 characters
    int len = strlen(k);
    if (len != 26)
    {
        printf("ERROR: Enter 26 LETTERS");
        return true;
    }

    // checking if the key characters are all letters and converting all to capital
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(k[i]))
        {
            if (islower(k[i]))
            {
                key[i] = toupper(k[i]);
            }
            else
            {
                key[i] = k[i];
            }
        }
        else
        {
            printf("ERROR: ENTER ONLY LETTERS\n");
            return true;
        }
    }

    // checking repeatition of the elements in key
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (key[i] == key[j])
            {
                printf("ERROR: REPEATING LETTERS.\n");
                return true;
            }
        }
    }

    // if the key matches all the parameters then returning false
    return false;
}

void cipher(string pt, int l)
{
    char ciphertext[l + 1];
    for (int i = 0; i < l; i++)
    {
        if (isalpha(pt[i]))
        {
            if (islower(pt[i]))
            {
                // lower 97 a, 122 z
                ciphertext[i] = tolower(key[pt[i] - 97]);
            }
            else
            {
                // upper 65 A, 90 Z
                ciphertext[i] = key[pt[i] - 65];
            }
        }
        else
        {
            ciphertext[i] = pt[i];
        }
    }
    ciphertext[l] = '\0';
    printf("ciphertext: %s\n", ciphertext);
}
