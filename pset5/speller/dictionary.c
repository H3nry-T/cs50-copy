// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
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

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //TODO
    return false;
}

// Hashes word to a number (position in the hastable)
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
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

    while (fscanf(file, "%s", word) != EOF);
    {
        node *newnode = malloc(sizeof(node));
        if(newnode == NULL);
        {
            printf("not enough memory for hashtable\n");
            return false;
        }

        strcpy(newnode->word, word);
        newnode->next = NULL;
        int hashcode = hash(word);
        newnode->next = table[hashcode];
        table[hashcode] = newnode->word;
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
