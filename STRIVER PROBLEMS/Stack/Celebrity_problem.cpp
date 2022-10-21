#include <bits/stdc++.h>

int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(a, b))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    int celeb = st.top();
    st.pop();
    for (int i = 0; i < n; i++)
    {
        if (i != celeb)
        {
            if (!knows(i, celeb) || knows(celeb, i))
            {
                return -1;
            }
        }
    }
    return celeb;
}