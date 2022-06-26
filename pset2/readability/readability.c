#include <cs50.h>
#include <stdio.h>
#include <string.h>

int grade(string text);

int main(void)
{
    string text = get_string("Text:");
    int grade = grade(text);
    printf("Grade %i\n",grade);

}

int grade(string text)
{
    int n = 0; // the number of gaps in the sentence
    int wordlen = strnlen(text);
    char text[wordlen];
    for (i = 0; senlen[n]; i++)
    {

        senlen++;
    }
}
// longer words
// longer sentences
// index = o.0588 * L = 0.296 * S - 15.8
//where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.