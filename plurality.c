#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define max 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[max];

int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{


    candidate_count = argc - 1;
    if (candidate_count > max)
    {
        printf("Maximum number of candidates is %i\n", max);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int maximum_vote = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maximum_vote)
        {
            maximum_vote = candidates[i].votes;
        } else
        for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == maximum_vote)

        {
            printf("%s\n", candidates[i].name);
        }
        }

    }

    return;
}