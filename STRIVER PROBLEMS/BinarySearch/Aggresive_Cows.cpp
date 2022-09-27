#include <bits/stdc++.h>
int isPossible(vector<int> positions, int c, int mid)
{
    int countplayers = 1;
    int room = positions[0];
    for (int i = 1; i < positions.size(); i++)
    {
        if (positions[i] - room >= mid)
        {
            countplayers++;
            room = positions[i];
        }
        if (countplayers == c)
        {
            return true;
        }
    }
    return false;
}
int chessTournament(vector<int> positions, int n, int c)
{
    sort(positions.begin(), positions.end());

    int low = 1;
    int high = positions[n - 1] - positions[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(positions, c, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}