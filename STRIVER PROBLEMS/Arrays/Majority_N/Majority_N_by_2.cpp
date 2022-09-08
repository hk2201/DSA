#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                candidate = nums[i];
            }
            if (nums[i] == candidate)
                count += 1;
            else
                count -= 1;
        }

        return candidate;
    }
};
int main()
{

    vector<int> nums = {4,4,2,4,3,4,4,3,2,4};
    Solution obj;
    int ans = obj.majorityElement(nums);
    cout << ans;

    return 0;
}
