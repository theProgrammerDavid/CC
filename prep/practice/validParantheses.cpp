#include <string>
#include <stack>
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> st;

        if (s.length() == 0)
            return true;
        if (s.length() % 2 == 1)
            return false;

        for (auto c : s)
        {

            if (c == ')' || c == '}' || c == ']')
            {
                if (st.size() == 0)
                    return false;
                if (c == ')' && st.top() != '(')
                    return false;
                if (c == '}' && st.top() != '{')
                    return false;
                if (c == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        return st.empty();
    }
};