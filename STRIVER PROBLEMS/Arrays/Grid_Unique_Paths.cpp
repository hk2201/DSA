#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    int m = 3;
    int n = 7;

    Solution obj;
    int ans = obj.uniquePaths(m, n);
    cout << "The No of Ways are " << ans;

    return 0;
}