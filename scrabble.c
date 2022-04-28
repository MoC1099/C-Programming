#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
char characters(char c);

int main(void)
{
    int sum1 = 0;
    int sum2 = 0;
    char c;

    // get a string
    string Player1 = get_string("Player 1: ");
    string Player2 = get_string("Player 2: ");

// make both strings UPPER case
    for (int i = 0, n = strlen(Player1); i < n; i++)
    {
        if (islower(Player1[i]))
        {
            Player1[i] = Player1[i] - 32;
        }
        else
        {
            Player1[i] = Player1[i];

        }
    }

    // make letter of word player 2 upper case
    for (int i = 0, n = strlen(Player2); i < n; i++)
    {
        if (islower(Player2[i]))
        {
            Player2[i] = Player2[i] - 32;
        }
        else
        {
            Player2[i] = Player2[i];

        }
    }

    // get values of word from player1
    for (int i = 0; i <= strlen(Player1); i++)
    {
        c = Player1[i];
        sum1 += characters(c);


    }

    // get values of word from player 2
    for (int i = 0; i <= strlen(Player2); i++)
    {
        c = Player2[i];
        sum2 += characters(c);
    }

    // compare values and print result
    if (sum1 > sum2)
    {
        printf("Player 1 wins! \n");
    }
    else if (sum2 > sum1)
    {
        printf("Player 2 wins! \n");

    }
    else
    {
        printf("Tie!\n");
    }
}

// assigned values to each char
char characters(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'N')
    {
        c = 1;
    }
    else if (c == 'D' || c == 'G')
    {
        c = 2;
    }
    else if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
    {
        c = 3;
    }
    else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
    {
        c = 4;
    }
    else if (c == 'K')
    {
        c = 5;
    }
    else if (c == 'X' || c == 'J')
    {
        c = 8;
    }
    else if (c == 'Q' || c == 'Z')
    {
        c = 10;
    }
    else
    {
        return 0;
    }
    return (c);
}
