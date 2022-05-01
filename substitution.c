#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
void newval(char c, string key);
int main(int argc, string argv[])
{
    char c;
    // putiing conditions to our argv(KEY)
    if (strlen(argv[1]) == 26)
    {
        for (int i = 0; i < strlen(argv[1]) ; i++)
        {
            // now check if all alphas
            if (! isalpha(argv[1][i]))
            {
                printf("not a valid key");
                return 1;
            }
            // now checking repeated elements in the array
            for (int x = i + 1; x < strlen(argv[1]) ; x++)
            {
                if ((argv[1][x]) == argv[1][i])
                {
                    printf("There must not be any repeated alphas");
                    return 1;
                }
            }
        }
    }
    else if (strlen(argv[1]) != 26)
    {
        return 1;
    }


    string plaintext = get_string("plaintext: ");
    printf("ciphertext:");

// iterate through the plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        c = plaintext[i];
        // there is space
        if (c == ' ')
        {
            printf("%c", plaintext[i]);
        }
// if there is a number
        if (c >= '0' && c <= '9')
        {
            printf("%c", plaintext[i]);
        }
        newval(c, argv[1]);
    }
    printf("\n");
}


void newval(char c, string argv)
{
    string aplha = "abcdefghijklmnopqrstuvwxyz";
    string APLHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// if  plaintext is in lower case
    if (islower(c))
    {
        for (int j = 0; j <= strlen(aplha); j++)
        {
            // if lower print lower
            if (c == aplha[j])
            {
                printf("%c", argv[j] + 32);
            }
        }

    }
// if  plaintext is in upper case
    if (isupper(c))
    {
        for (int j = 0; j <= strlen(APLHA); j++)
        {
            // if lower print lower
            if (c == APLHA[j])
            {
                printf("%c", argv[j]);
            }
        }
    }
}