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
    string text = get_string("Text:");
    // calculate letters
    int letter = letters(text);
    // calculate sentences
    int sentence = sentences(text);
    // calculate words
    int word = words(text);
    // calculate L is the average number of letters per 100 words in the text
    float L = letter / (float) word * 100;
    // calculate S is the average number of sentences per 100 words in the text
    float S = sentence / (float) word * 100;

    int index = 0.0588 * L - 0.296 * S - 15.8;
    
    if (index < 1)
    {
        printf("Before Grade 1\n")
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",index);
    }

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
    int words = 1;
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

// index = 0.0588 * L - 0.296 * S - 15.8
//Congratulations! Today is your day. You're off to Great Places! You're off and away!
//65 letters, 4 sentences, and 14 words.