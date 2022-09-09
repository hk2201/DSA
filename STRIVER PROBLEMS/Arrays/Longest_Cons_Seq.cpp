#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int ans = 1;
        int prev = nums[0];
        int cur = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev + 1)
            {
                cur++;
            }
            else if (nums[i] != prev)
            {
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {100,200,1,2,3};

    Solution obj;
    int ans = obj.longestConsecutive(nums);
    cout<<"The count is "<<ans;




    return 0;
}