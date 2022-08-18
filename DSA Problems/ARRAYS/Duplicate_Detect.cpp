#include <iostream>
using namespace std;
class Solution
{
public:
    int findDuplicate(int arr[])
    {

        for (int i = 0; i < 5; i++)
        {
            if (arr[i] == arr[i + i])
            {
                return arr[i];
            }
        }
        return 0;
    }
};

int main()
{
    int n = 5;
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    Solution hk;
    cout << hk.findDuplicate(arr);
    return 0;
}