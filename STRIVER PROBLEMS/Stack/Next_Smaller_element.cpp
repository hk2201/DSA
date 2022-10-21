vector<int> Solution::prevSmaller(vector<int> &A)
{
    vector<int> ans(A.size(), -1);
    stack<int> st;

    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && st.top() >= A[i]) 
        {
            st.pop();
        }

        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}
