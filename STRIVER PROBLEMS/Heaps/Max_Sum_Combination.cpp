vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n = A.size();
    
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> myset;
    vector<int> ans;
    pq.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));
    myset.insert(make_pair(n-1,n-1));
    
    for(int count = 0; count<C;count++){
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();
        
        int x = p.first;
        ans.push_back(x);
        
        int i = p.second.first;
        int j = p.second.second;
        
        int sum = A[i-1] + B[j];
        
        pair<int,int> temp = make_pair(i-1,j);
        
        if(myset.find(temp) == myset.end()){
            pq.push(make_pair(sum,temp));
            myset.insert(temp);
        }
        
        sum = A[i] + B[j-1];
        
        temp = make_pair(i,j-1);
        
        if(myset.find(temp)== myset.end()){
            pq.push(make_pair(sum,temp));
            myset.insert(temp);
        }
    }
    return ans;
}






// Solution 2;














vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    vector<int> total;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            int x = A[i] + B[j];
            total.push_back(x);
        }
    }

    priority_queue<int> pq;
    for (int i = 0; i < total.size(); i++)
    {
        pq.push(total[i]);
    }

    vector<int> ans;
    int count = C;
    while (count > 0)
    {
        int num = pq.top();
        pq.pop();
        ans.push_back(num);
        count--;
    }

    return ans;
}


























