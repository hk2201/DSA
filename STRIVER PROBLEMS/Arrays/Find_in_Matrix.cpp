#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        bool found = false;
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == target)
                {
                    found = true;
                }
            }
        }
        return found;
    }
};

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution obj;
    cout << "Found or not " << obj.searchMatrix(matrix, 10);

    return 0;
}