#include <bits/stdc++.h>
using namespace std;

vector<int> missing_repeated_number(const vector<int> &array)
{
    int n = array.size() + 1;

    vector<int> substitute(n, 0); // initializing the substitute array with 0 of size n+1.

    vector<int> ans; // initializing the answer  array .

    for (int i = 0; i < array.size(); i++)
    {
        substitute[array[i]] = substitute[array[i]] + 1;
    }

    for (int i = 1; i <= array.size(); i++)
    {
        if (substitute[i] == 0 || substitute[i] > 1)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    vector<int> array;
    array = {0, 2, 2};
    vector<int> print = missing_repeated_number(array);
    cout << print[0] << " " << print[1];
}

// Second Solution

// vector<int>missing_repeated_number(const vector<int> &A) {
//     long long int len = A.size();

//     long long int S = (len * (len+1) ) /2;
//     long long int P = (len * (len +1) *(2*len +1) )/6;
//     long long int missingNumber=0, repeating=0;

//     for(int i=0;i<A.size(); i++){
//        S -= (long long int)A[i];
//        P -= (long long int)A[i]*(long long int)A[i];
//     }

//     missingNumber = (S + P/S)/2;

//     repeating = missingNumber - S;

//     vector <int> ans;

//     ans.push_back(repeating);
//     ans.push_back(missingNumber);

//     return ans;
// }