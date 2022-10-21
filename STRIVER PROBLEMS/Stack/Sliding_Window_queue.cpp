class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());

        for (int i = k; i < nums.size(); i++)
        {
            if (dq.front() == nums[i - k])
            {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }

        return ans;
    }
};

// optimal

vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();

    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}
