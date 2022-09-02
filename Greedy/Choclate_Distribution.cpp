#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// If 5 packeets to be distributed from array then max packets - min packets should be minimum.

class Solution
{
public:
    long long mindiff(vector<long long> a, long long m, long long n)
    {
        sort(a.begin(), a.end());

        int i = 0;
        int j = m - 1;
        int min = INT_MAX; // just to say that it has something max.
        while (j < n)
        {
            int diff = a[j] - a[i];
            if (diff < min)
            {
                min = diff;
            }
            // We will check for evry 5 subarrays and get diff.
            i++;
            j++;
        }
        return min;
    }
};

int main()
{
    long long n;
    cout << "Enter Size of array" << endl;
    cin >> n;
    vector<long long> v;
    long long x;
    for (long long i = 0; i < n; i++)
    {
        cout << "Enter" << endl;
        cin >> x;
        v.push_back(x);
    }

    long long m;
    cout << "Enter Number of students" << endl;
    cin >> m;
    Solution obj;

    cout << obj.mindiff(v, m, n);

    return 0;
}