#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int words_calc(string text, int len);
float l_calc(string text, int len, int word);
float s_calc(string text, int len, int word);
void result(float letters, float sentence);

int main(void)
{
    string input = get_string("Text: ");
    int len = strlen(input);

    // calculating words
    int words = words_calc(input, len);

    // calculating l
    float l = l_calc(input, len, words);

    // calculating s = average number of sentences per 100 words
    float s = s_calc(input, len, words);

    // result
    result(l, s);
}

int words_calc(string text, int len)
{
    int n = 0;
    for (int i = 0; i <= len; i++)
    {
        if (text[i] == 32)
        {
            n += 1;
        }
        if (i == len)
        {
            n += 1;
        }
    }
    return n;
}

float l_calc(string text, int len, int word)
{
    int n = 0;
    for (int i = 0; i <= len; i++)
    {
        if ((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97))
        {
            n += 1;
        }
    }

    // calculaating l = average number of letters in per 100 words
    float l = (n / (float) word) * 100.00;
    return l;
}

float s_calc(string text, int len, int word)
{
    int n = 0;
    for (int i = 0; i <= len; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            n += 1;
        }
    }
    float s = (n / (float) word) * 100.00;
    return s;
}

void result(float letters, float sentence)
{
    // calculating readebility by Coleman-Liau index
    float index = 0.0588 * letters - 0.296 * sentence - 15.8;
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
