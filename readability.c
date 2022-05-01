
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// The program is designed to return the Grade level of a sentence/paragraph.
int main() {
    char c;
    int words= 1;
    int sentence = 0;
    int letters = 0;
    int Grade = 0;

    float index=0;
    string statement = get_string("Enter the sentence ");
    // make lower case to upper
     for (int i = 0, n = strlen(statement); i < n; i++)
    {
        if (isupper(statement[i]))
        {
            statement[i] = statement[i] + 32;
        }
        else
        {
            statement[i] = statement[i];
        }
    }

    // get the number of words, sentences and letters from the input.
    for (int i = 0; i <= strlen(statement); i++)
    {
        if(statement[i] == ' ')
        {
        words = words + 1;
        }
        if(statement[i] == '?' || statement[i] == '!' || statement[i] == '.')
        {
            sentence = sentence + 1;
        }
        // need to get # of letter in a sentence
        if (statement[i] >= 'a' && statement[i] <= 'z')
        {
            letters = letters + 1;
        }
    }

    float S = (float) letters/ (float) words * 100;
    float L = (float) sentence/(float) words *100 ;

    // using Coleman-Liau index formula to get the grade level of the text
    index = (0.0588 * S - 0.296 * L - 15.8);
    index = round(index);
     Grade =  index;
    // print out the results.
    if(Grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(Grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", Grade);
    }
}