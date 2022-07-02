bool vote(int rank, string name, int ranks[])
{
    int candindex = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            candindex = i;
            break;
        }
    }
    if (candindex == 0)
    {
        return false;
    }
    ranks[rank] = candindex;
    return true;
}

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
    if (candindex == 0)
    {
        return false;
    }
}

void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] - preferences[j][i] > 0)
            {
                pair_count++;
                pairs[i].winner = preferences[i][j]
            }
            else if (preferences[i][j] - preferences[j][i] < 0)
            {
                pair_count++;
                pairs[i].loser =
            }
        }
    }
    return;
}