class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int num : nums)
        {
            map[num]++;
        }

        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (auto it : map)
        {
            pq.push(make_pair(it.second, it.first));
        }

        while (k--)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }
        return res;
    }
};