#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // ranks is an array that stores the preferences of the voter temporarily
    // vote fuctions takes the argument name and check if it is present in the global array
    // candidates if the name is in the candiates list update the ranks array at the rank position
    // with the candidates index number
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // this function updates the preferences[i][j] array where, i is the row for each of the
    // candidate, and j is the position inside the row that stores the value of how much the i
    // candidate is prefered over j (curent candidate) in the following the loop with variable i
    // loops through the ranks array for each ranking [index], means it just checks which row(in the
    // preferences table) comes first in the ranking and loop with j var, checks where to add the
    // preference in the table by looping through the remaining values from the ranks[]
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // The function should add all pairs of candidates where one
    // candidate is preferred to the pairs array. A pair of candidates who are tied (one is not
    // preferred over the other) should not be added to the array. The function should update the
    // global variable pair_count to be the number of pairs of candidates.
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // the pairs are updated only if 'i' is winner, and doesn't record the loser
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                // this was in use for previous version but check50 doesnot support this even if
                // this is correct && to use the below first declare the following global variab
                // "int strength[MAX*(Max-1)/2];" as global var
                // strength[pair_count] = prefernces[i][j] - preferences[j][i]
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // The function should sort the pairs array in decreasing order of strength of victory, where
    // strength of victory is defined to be the number of voters who prefer the preferred candidate.
    // If multiple pairs have the same strength of victory, you may assume that the order does not
    // matter.
    for (int i = 0; i < pair_count; i++)
    {
        int index = i;
        int strength = preferences[pairs[i].winner][pairs[i].loser] -
                       preferences[pairs[i].loser][pairs[i].winner];
        int check_strength;
        for (int j = i + 1; j < pair_count; j++)
        {
            check_strength = preferences[pairs[j].winner][pairs[j].loser] -
                             preferences[pairs[j].loser][pairs[j].winner];
            if (strength < check_strength)
            {
                strength = check_strength;
                index = j;
            }
        }

        if (index != i)
        {
            pair temp = pairs[i];

            pairs[i] = pairs[index];

            pairs[index] = temp;
        }
    }
    return;
    /* the below version is previous that is not supported by check50
    **to use this  follow the comments int the add_pairs function first to cretrength var
    first

    int index;
    pair temp;
    int strength_temp;
    for (int i = 0; i < pair_count; i++)
    {
        index = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            if (strength[index] < strength[j])
            {
                index = j;
            }
        }
        if (index != i)
        {
            // assigning the pair at i to the temp
            temp = pairs[i];
            strength_temp = strength[i];

            // assigning the pair at index (largest strength)
            pairs[i] = pairs[index];
            strength[i] = strength[index];

            // assigning the temporerily stored values back to the index posit
            pairs[index] = temp;
            strength[index] = strength_temp;
        }
    }
    return;
    }
    */
}

// Lock pairs into the candidate graph in order, without creating cycles
bool circle(int winner, int loser)
{
    if (winner == loser)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] == true)
        {
            if (circle(winner, i) == true)
            {
                return true;
            }
        }
    }
    return false;
}

void lock_pairs(void)
{
    // The function should create the locked graph, adding all edges in decreasing order of victory
    // strength so long as the edge would not create a cycle.
    for (int i = 0; i < pair_count; i++)
    {
        if (circle(pairs[i].winner, pairs[i].loser) == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // The function should print out the name of the candidate who is the source of the graph. You
    // may assume there will not be more than one source.
    int counter;
    for (int j = 0; j < candidate_count; j++)
    {
        counter = 0;
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][j] == false)
            {
                counter++;
            }
        }
        if (counter == candidate_count)
        {
            printf("%s\n", candidates[j]);
        }
    }
    return;
}

// void print_winner(void)
// {
//     int counter;
//     for (int j = 0; j < candidate_count; j++)
//     {
//         counter = 0;
//         for (int i = 0; i < candidate_count; i++)
//         {
//             if (!locked[i][j])
//             {
//                 counter++;
//             }
//         }
//         if (counter == candidate_count)
//         {
//             printf("%s\n", candidates[j]);
//         }
//     }
//     return;
// }
