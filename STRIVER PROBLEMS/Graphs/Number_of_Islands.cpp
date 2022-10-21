class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vector<int> delta = {0, 1, 0, -1, 0};
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delta[i];
                int ncol = c + delta[i + 1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }

            // This is for all diagonals

            // for(int delrow = -1 ; delrow<=1 ;delrow++){
            //     for(int delcol = -1 ; delcol<=1 ; delcol++){
            //         int nrow = r + delrow;
            //         int ncol = c + delcol;
            //         if(nrow >=0 && nrow<n && ncol >=0 && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
            //             vis[nrow][ncol] = 1;
            //             q.push({nrow,ncol});
            //         }
            //     }
            // }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
    }
};