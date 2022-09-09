#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    int cnt;

    void merge(vector<int> &nums, int low, int mid, int high)
    {
        int i = low, j = mid + 1;
        while (i <= mid && j <= high)
        {
            if ((long)nums[i] > (long)2 * nums[j])
            {
                j++;
                cnt += (mid + 1 - i);
            }
            else
            {
                i++;
            }
        }
        sort(nums.begin() + low, nums.begin() + high + 1);
        return;
    }

    void mergeSort(vector<int> &nums, int low, int high)
    {
        int mid = (low + high) / 2;
        if (low == high)
        {
            return;
        }
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int> &nums)
    {
        cnt = 0;
        if (nums.empty())
        {
            return 0;
        }
        mergeSort(nums, 0, nums.size() - 1);

        return cnt;
    }
};

int main(){
    vector<int> nums = {3,4,1,0,7};
     Solution obj;
     int ans = obj.reversePairs(nums);
     cout<<"The Number of Reverse Pairs are "<<ans;


    return 0;
}