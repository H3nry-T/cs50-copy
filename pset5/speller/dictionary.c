// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];
unsigned long hashcode;
unsigned long wordcount;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    hashcode = hash(word);
    node *traversal = table[hashcode];
    while (traversal != NULL)
    {
        if (strcasecmp(word, traversal->word) == 0)
        {
            return true;
        }
        else
        {
            traversal = traversal->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file  = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("unable to open the %s\n", dictionary);
        return false;
    }

    //buffer
    char scanword[LENGTH + 1];
    while(fscanf(file, "%s", scanword) != EOF)
    {
        node *newword = malloc(sizeof(node));
        if (newword == NULL)
        {
            printf("cannot allocate any more memory for hashtable\n");
            return false;
        }

        strcpy(newword->word, scanword);
        hashcode = hash(scanword);
        newword->next = table[hashcode];
        table[hashcode] = newword;
        wordcount++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *temp;
    node *traversal;

    int i;
    for (i = 0; i < N; i++)
    {
        traversal = table[i];
        while (traversal != NULL)
        {
            temp = traversal;
            traversal = traversal->next;
            free(temp);
        }
        if (traversal == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
