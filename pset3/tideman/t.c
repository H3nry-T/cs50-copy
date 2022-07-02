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