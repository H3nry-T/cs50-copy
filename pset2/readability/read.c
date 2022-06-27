#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int letters(string text);
int sentences(string text);
int words(string text);

int main(void)
{
    string text = get_string("TEXT:\n");

    int letter = letters(text);
    printf("this text has %i letters\n", letter);
}

int letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i])) // 'A' 'z'
        {
            letters++;
        }
    }
    return letters;
}
int sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // '.' '!' '?'
        {
            sentences++;
        }
    }
    return sentences;
}
int words(string text)
{
    int words = 0;
    int i = 0;
    while (text[i] != '\0') //chraracter is not NULL
    {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            words++;
        }
        i++;
    }
    return words;
}