// Implements a dictionary's functionality
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "dictionary.h"
#include <string.h>
#include <stdlib.h>

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
int hashcode;
unsigned int wordcount;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    hashcode = hash(word);
    //traversal pointer at head node.

    node *traversal;
    traversal = table[hashcode];
    while(traversal != NULL)
    {
        int indict = strcasecmp(word, traversal->word);
        if (indict == 0)
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

// Hashes word to a number (position in the hastable)
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int sum = 0;

    for (int i = 0, i < strlen(word), i++)
    {
        sum += word[i];
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    //creating nodes
    if (file == NULL);
    {
        printf("cannot open the dictionary file\n");
        return false;
    }

    //dictionary word is this size is a buffer.
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *newnode = malloc(sizeof(node));
        if(newnode == NULL)
        {
            printf("not enough memory for hashtable\n");
            return false;
        }

        strcpy(newnode->word, word);
        hashcode = hash(word);
        newnode->next = table[hashcode];
        table[hashcode] = newnode;
        wordcount++;
    }
    fclose(file);
    free(newnode);
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

    return false;
}
