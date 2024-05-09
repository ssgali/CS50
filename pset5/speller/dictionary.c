// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "dictionary.h"
int sod = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N  ;
#define N 1000

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int n = hash(word);
    node *temp = NULL;
    temp = table[n];
    while (temp != NULL)
    {
        if (strcasecmp(word, temp->word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    char nwword[46];
    strcpy(nwword, word);
    for (int q = 0 ; q < strlen(nwword) ; q++)
    {
        if (isupper(word[q]))
        {
            nwword[q] = tolower(nwword[q]);
        }
    }
    unsigned int hash = 0;
    for (int i = 0 ; i < strlen(nwword) ; i++)
    {
        hash = hash + nwword[i];
    }
    hash = hash % N;
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dicn = fopen(dictionary, "r");
    char nword[46];
    if (dicn == NULL)
    {
        fclose(dicn);
        return false;
    }
    while (true)
    {
        if (fscanf(dicn, "%s", nword) == EOF) // reading from file
        {
            fclose(dicn);
            return true;
        }
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(dicn);
            return false;
        }
        strcpy(new_node->word, nword);
        new_node->next = NULL;
        unsigned int num = hash(nword);
        if (table[num] == NULL)
        {
            table[num] = new_node;
        }
        else
        {
            new_node->next = table[num];
            table[num] = new_node;
        }
        sod++;                  //Size of Dictionary
    }
    fclose(dicn);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return sod ;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int num = 0 ; num < N  ; num++)
    {
        node *cursor = NULL;
        node *temp = NULL;
        cursor = table[num];
        temp = table[num];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
