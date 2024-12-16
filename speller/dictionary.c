// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = (26 * 26) + 1;

// size function count integer
unsigned int size_counter = 0;

// Hash table
node *table[N];

FILE *loadfile = NULL;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *ptr = table[hash(word)];
    if (ptr == NULL)
    {
        return false;
    }

    do
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }
    while (ptr != NULL);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int first = toupper(word[0]) - 'A';
    int second = toupper(word[1]) - 'A';
    unsigned int index = (first * 26) + second;
    if (index > N || index < 0)
    {
        index = N - 1;
    }
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // setting the hash table to null
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // Loading the dictionary
    loadfile = fopen(dictionary, "r");
    if (loadfile == NULL)
    {
        return false;
    }
    char buffer[LENGTH + 1];
    unsigned int index;
    while (fscanf(loadfile, "%s", buffer) != EOF)
    {
        node *address = malloc(sizeof(node));
        if (address == NULL)
        {
            return false;
        }
        strcpy(address->word, buffer);
        index = hash(buffer);
        address->next = table[index];
        table[index] = address;
        size_counter++;
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        if (cursor == NULL)
        {
            continue;
        }

        do
        {
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
        while (cursor != NULL);
    }
    fclose(loadfile);
    return true;
}
