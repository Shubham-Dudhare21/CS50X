#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int values[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score_calculation(string a);
void result(int a, int b);

int main(void)
{
    // Input from user
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    for (int i = 0, a = strlen(player1); i < a; i++)
    {
        player1[i] = toupper(player1[i]);
    }

    for (int i = 0, a = strlen(player2); i < a; i++)
    {
        player2[i] = toupper(player2[i]);
    }

    // scores of both player and comparison
    int score1 = score_calculation(player1);
    int score2 = score_calculation(player2);

    // printing the result
    result(score1, score2);
}

int score_calculation(string a)
{
    int len = strlen(a);
    int score = 0;
    for (int i = 0; i < len; i++)
    {
        score += values[((int) a[i]) - 65];
    }
    return score;
}

void result(int a, int b)
{
    if (a > b)
    {
        printf("Player 1 wins!\n");
    }
    else if (a < b)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
