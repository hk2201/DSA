// We are given two sorted arrays. We need to merge these two arrays such that the initial numbers (after complete sorting) are in the first array and the remaining numbers are in the second array. Extra space is allowed in O(1).

#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void findDuplicate(int arr1[], int arr2[])
    {
        int n1 = 5;
        int n2 = 4;
        vector<int> end;
        vector<int> front;
        end.push_back(arr1[n1 - 1]);
        for (int i = 0; i < n1 - 1; i++)
        {
            front.push_back(arr1[i]);
        }
        for (int i = 0; i < n1 - 2; i++)
        {
            front.push_back(arr2[i]);
        }
        end.push_back(arr2[n2 - 1]);
        cout << endl;
        cout << "End Elements are" << endl;
        for (int i = 0; i < end.size(); i++)
        {
            cout << end[i] << " ";
        }
        cout << endl;
        cout << "front Elements are" << endl;
        for (int i = 0; i < front.size(); i++)
        {
            cout << front[i] << " ";
        }
    }
};

int main()
{
    int n1 = 5;
    int n2 = 4;
    int arr1[5];
    int arr2[4];

    for (int i = 0; i < 5; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> arr2[i];
    }
    Solution hk;
    hk.findDuplicate(arr1, arr2);
    return 0;
}