#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> Set;
        int start = 0;
        int end = 0;
        int maxx = 0;

        while (start < s.size())
        {
            auto it = Set.find(s[start]);

            if (it == Set.end())
            {
                maxx = max(maxx, start - end + 1);
                Set.insert(s[start]);
                start++;
            }
            else
            {
                Set.erase(s[end]);
                end++;
            }
        }

        return maxx;
    }
};

int main(){

    string s = "abcabcbb";

    Solution obj;
    int ans = obj.lengthOfLongestSubstring(s);
    cout<<"The lenght of the longest substring without any repeatation is "<<ans;

    return 0;
}