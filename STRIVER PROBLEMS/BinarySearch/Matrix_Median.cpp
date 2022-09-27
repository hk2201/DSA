#include <algorithm>
int getMedian(vector<vector<int>> &matrix)
{
    vector<int> ans;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            int num = matrix[i][j];
            ans.push_back(num);
        }
    }

    sort(ans.begin(), ans.end());
    int mid = (ans.size()) / 2;
    int anss = ans[mid];

    return anss;
}

// Binary Search