#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverWords(string S)
    {
        string ans = "";
        string temp = "";
        for (int i = S.length(); i >= 0; i--)
        {
            if (S[i] == '.')
            {
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans.push_back('.');
                temp = "";
            }
            else
            {
                temp.push_back(S[i]);
            }
        }
        // This step for last Word as there will be no full stop.
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        temp = "";

        return ans;
    }
};

int main()
{
    string S;
    cout << "Enter the String" << endl;
    cin >> S;

    Solution obj;
    string s = obj.reverWords(S);
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];
    }

    return 0;
}
