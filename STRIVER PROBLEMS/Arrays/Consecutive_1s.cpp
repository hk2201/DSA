#include <iostream>
#include <vector>
using namespace std;

int consecutive(vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int ans = consecutive(nums);

    cout << ans;

    return 0    ;
}