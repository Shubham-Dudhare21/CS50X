#include <cs50.h>
#include <stdio.h>

void avg(int n, int a[]);

int main(void)
{
    int n = get_int("total subjects: ");
    int score[n];
    for (int i = 0; i < n; i++)
    {
        score[i] = get_int("Subject %i score: ", i+1);
    }
    avg(n, score);
}

void avg(int n, int a[])
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += a[i];
    }
    printf("avg: %f\n", total / 3.0);
}
