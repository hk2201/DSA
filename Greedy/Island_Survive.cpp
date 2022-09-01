#include <iostream>
using namespace std;

class Solution
{
public:
    int minDays(int S, int N, int M)
    {
        int sundays = S / 7;
        int buyingdays = S - sundays;
        int totalfood = S * M;
        int ans = 0;
        if (totalfood % N == 0)
        {
            ans = totalfood / N;
        }
        else
        {
            ans = totalfood / N + 1;
        }
        if (ans <= buyingdays)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{

    int S, N, M;
    cout << "Enter how much can you buy per day" << endl;
    cin >> S;
    cout << "Enter how much you need to survuve per day" << endl;
    cin >> N;
    cout << "How many days to survive" << endl;
    cin >> M;

    Solution ob;
    int ans = ob.minDays(S, N, M);
    cout << ans;

    return 0;
}