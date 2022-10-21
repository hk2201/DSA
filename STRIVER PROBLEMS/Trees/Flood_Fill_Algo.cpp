class Solution
{
public:
    void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int sr, int sc, int color, int ini, vector<int> delrow, vector<int> delcol)
    {
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == ini && ans[nrow][ncol] != color)
            {
                dfs(image, ans, nrow, ncol, color, ini, delrow, delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> delrow = {-1, 0, +1, 0};
        vector<int> delcol = {0, +1, 0, -1};
        dfs(image, ans, sr, sc, color, ini, delrow, delcol);

        return ans;
    }
};