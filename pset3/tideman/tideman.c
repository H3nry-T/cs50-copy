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
        for (int j = i + 1; j < candidate_count; j++)
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

int victorystgh(int i)//i is any index position
{
    return preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        int maxv = victorystgh(i);
        int higheststrength_index = i;
        for (int j = i + 1; j < pair_count - 1; j++)
        {
            if (victorystgh(j) > maxv)
            {
                maxv = victorystgh(j);
                higheststrength_index = j;
            }
        }
        if (higheststrength_index != i)
        {
            pair swapwith = pairs[higheststrength_index];//we want highstrength index pair to swap with the starting pair.
            pairs[higheststrength_index]= pairs[i];
            pairs[i] = swapwith;
        }
    }
    return;
}

bool cycleismade(int finalloser, int startwinner) //checks is a cycle is made true or false?
{
    if (finalloser == startwinner) //does the loser candidate point back to the winner? if true, we have a loop .
    {
        return true; //because we have looped around back to the winner.
    }
    for (int i = 0; i < candidate_count; i++)//does the loser point to any other candidates?
    {
        if (locked[finalloser][i]) //does the loser point to any other candidate? if true check if it creates a cycle AGAIN
        {
            if (cycleismade(i, startwinner))//since the loser points to another candidate, do they loop back round to the starting winner?
            {
                return true;
            }
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)//look through the pairs, if the loser, links back up to the winner, then we cannot create an edge/arrow
    {
        if (!cycleismade(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int j = 0; j < candidate_count; j++)
    {
        int count = 0;// counting the number of falses in 1 column
        for (int i = 0; i < candidate_count; i++)
        {
            if(locked[i][j] == false)// if candidate column is false in the locked array, we know that this candidate has no arrows pointing at him/her.
            {
                count++;// add to the number of falses.
                if (count == candidate_count)
                {
                    printf("%s\n", candidates[j]);
                }
            }
        }
    }
    return;
}