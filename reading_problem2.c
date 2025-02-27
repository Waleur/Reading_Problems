#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    
    int words = count_words(text);
    int sentences = count_sentences(text);
    
    printf("Words: %d\n", words);
    printf("Sentences: %d\n", sentences);
}

int count_words(string text)
{
    int words = 0;
    bool in_word = false;
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            words++;
            in_word = true;
        }
    }
    
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    
    return sentences;
}
