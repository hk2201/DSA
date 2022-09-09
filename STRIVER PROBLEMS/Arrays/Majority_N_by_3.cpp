#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int candi1 = INT_MIN;
        int candi2 = INT_MIN;
        int life1 = 0;
        int life2 = 0;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {

            if (candi1 == nums[i])
            {
                life1++;
            }
            else if (candi2 == nums[i])
            {
                life2++;
            }
            else if (life1 == 0)
            {
                candi1 = nums[i];
                life1 = 1;
            }
            else if (life2 == 0)
            {
                candi2 = nums[i];
                life2 = 1;
            }
            else
            {
                life1--;
                life2--;
            }
        }

        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (candi1 == nums[i])
            {
                count1++;
            }
            if (candi2 == nums[i])
            {
                count2++;
            }
        }

        if (count1 > n / 3)
        {
            ans.push_back(candi1);
        }
        if (count2 > n / 3)
        {
            ans.push_back(candi2);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {11, 33, 33, 11, 33, 11};

    Solution obj;
    vector<int> ans = obj.majorityElement(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}