class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
            {
                st.push(it);
            }
            else
            {
                if (st.size() == 0)
                {
                    return false;
                }
                char x = st.top();
                st.pop();
                if ((it == ')' && x == '(') || (it == '}' && x == '{') || (it == ']' && x == '['))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};