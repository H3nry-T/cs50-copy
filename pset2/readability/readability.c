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
    float L = letter / word * 100;
    // calculate S is the average number of sentences per 100 words in the text
    float S = sentence / word * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    printf("Grade %i\n",grade);

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
        if (text[i] == 46 || text[i] == 33 || text[i] == 63) // '.' '!' '?'
        {
            sentences++;
        }
    }
    return sentences;
}
int words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' .,;\n\t') // ' '
        {
            words++;
        }
    }
    return words;
}

// index = 0.0588 * L - 0.296 * S - 15.8
//Congratulations! Today is your day. You're off to Great Places! You're off and away!
//65 letters, 4 sentences, and 14 words.