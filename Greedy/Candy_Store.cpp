#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies, candies + n);
        int mini = 0;
        int buy = 0;
        int freee = n - 1;
        while (buy <= freee)
        {
            mini = mini + candies[buy];
            buy++;
            freee = freee - k;
        }

        int maxi = 0;
        buy = n - 1;
        freee = 0;
        while (freee <= buy)
        {
            maxi = maxi + candies[buy];
            buy--;
            freee = freee + k;
        }
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);

        return ans;
    }
};

int main()
{
    int k, n;
    cout << "Enter the amount of free candies to buy" << endl;
    cin >> k;
    cout << "Enter the size of array" << endl;
    cin >> n;

    int candies[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the prize" << endl;
        cin >> candies[i];
    }

    Solution ob;
    vector<int> v = ob.candyStore(candies, n, k);
    cout << v[0] << " " << v[1];

    return 0;
}