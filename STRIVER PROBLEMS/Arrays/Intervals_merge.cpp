#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty())
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            vector<int> &v = ans.back();
            int y = v[1];
            if (y >= intervals[i][0])
            {
                v[1] = max(y, intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
    vector<vector<int>> ans = merge(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
}