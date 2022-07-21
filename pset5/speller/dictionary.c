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
const unsigned int N = 26;

// Hash table
node *table[N];
unsigned long hashcode;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file  = fopen(dictionary, "r");
    if (file == NULL);
    {
        printf("unable to open the dictionary\n");
        return false;
    }

    //buffer
    char scanword[LENGTH + 1];
    while(fscanf(file, %s, scanword) != EOF)
    {
        node *newword = malloc(sizeof(node));
        hashcode = hash(word);
        strcpy(table[hashcode]->word, scanword);
        newword = table[hashcode];
        table[hashcode] = newword;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
