#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; i++)
        {
            preferences[ranks[i]][ranks[j]] += 1; //ranks[i] is preferred over ranks[j]
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void) //look into the preferences array.
{
    for (int i = 0; i < candidate_count; i++) //check each row candidate
    {
        for (int j = 0; j < candidate_count; j++) //check if the row beat the column (larger vote count)
        {
            if (preferences[i][j] > preferences[j][i]) //i wins against j vs j wins against i
            {
                pair addpair = {i, j};//winner is i and loser is j
                pairs[pair_count] = addpair;//make pairs array, of alice bob, bob chalie, etc.
                pair_count++;//if an extra pair is found with a winner => add the pair_count (increases array size)
            }
            //no else if() statement
            //A vs B and B vs A (A is i B is j)
            //B vs A and A vs B? this makes else if() redundant.
            //(B is i A is j)
            //because this loop covers this scenario already
            // else if (preferences[j][i] > preferences[i][j])
            // {
            //     pair addpair = {j, i};
            //     pairs[pair_count] = addpair;
            //     pair_count++;
            // }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        int max_v = preferences[pairs[i]][pairs[j]]
        for (int j = i + 1; j < pair_count - 1; j++)
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}