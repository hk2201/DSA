class MinStack
{
    stack<long long> st;
    long long mini;

public:
    MinStack()
    {
        mini = INT_MAX;
    }

    void push(int val)
    {
        long long vall = val;
        if (st.empty())
        {
            mini = vall;
            st.push(vall);
        }
        else
        {
            if (vall < mini)
            {
                st.push(2 * vall * 1LL - mini);
                mini = vall;
            }
            else
            {
                st.push(vall);
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        long long el = st.top();
        st.pop();
        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        long long el = st.top();
        if (el < mini)
        {
            return mini;
        }
        else
        {
            return el;
        }
    }

    int getMin()
    {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */