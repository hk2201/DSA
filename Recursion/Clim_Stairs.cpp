#include <iostream>
using namespace std;
// In how many ways person can reach to Nth Stair.

int noOfWays(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    return noOfWays(n - 1) + noOfWays(n - 2);
}

int main()
{
    cout << "Enter No of stairs" << endl;
    int n;
    cin >> n;

    int ans = noOfWays(n);
    cout << ans;

    return 0;
}