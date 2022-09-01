// Activity Selection Problem
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> // For sorting and all that
// #include<bits/stdc++.h>

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int> > v;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);

        int count = 1;
        int ansEnd = v[0].second;
        for (int i = 1; i < n; i++)  // first meeting is alrady doen so we can start from 1;
        {
            if (v[i].first > ansEnd)
            {
                count++;
                ansEnd = v[i].second;
            }
        }

        return count;
    }
};


int main(){
    int n ;
    cout<<"Enter Size"<<endl;
    cin>>n;
    int start[n];
    int end[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Start"<<endl;
        cin>>start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter End"<<endl;
        cin>>end[i];
    }

    Solution ob;
    int ans = ob.maxMeetings(start,end,n);
    cout<<"Max Meetings are "<<ans;

    return 0;
    
    
}