//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);

        int countWeight = 0;
        double finalVal = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (countWeight + arr[i].weight <= W)
            {
                countWeight += arr[i].weight;
                finalVal += arr[i].value;
            }
            else
            {
                int remain = W - countWeight;
                finalVal += ((double)arr[i].value / (double)arr[i].weight) * remain;
                break;
            }
        }

        return finalVal;
    }
};
