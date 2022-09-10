#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{
    unordered_map<int, int> visited;
    int cpx = 0;
    long long c = 0;
    for (int i = 0; i < A.size(); i++)
    {
        cpx ^= A[i];
        if (cpx == B)
            c++;
        int h = cpx ^ B;

        if (visited.find(h) != visited.end())
        {
            c = c + visited[h];
        }
        visited[cpx]++;
    }
    return c;
}

int main(){

    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;

    int ans = solve(A,B);
    cout<<"No of Subarrays with Given XOR are "<<ans;


    return 0;
}