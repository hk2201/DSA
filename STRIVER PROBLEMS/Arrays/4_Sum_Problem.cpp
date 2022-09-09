#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long sum;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++)
            {

                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int right = n - 1;
                int left = j + 1;
                while (left < right)
                {
                    sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum == target)
                    {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[left]);
                        t.push_back(nums[right]);
                        ans.insert(t);
                        left++;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (auto it : ans)
        {
            res.push_back(it);
        }
        return res;
    }
};

int main()
{

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution obj;

    vector<vector<int>> ans = obj.fourSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}