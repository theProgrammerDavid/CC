#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    std::map<char, int> values;

public:
    Solution()
    {
        values.insert({'M', 1000});
        values.insert({'D', 500});
        values.insert({'C', 100});
        values.insert({'L', 50});
        values.insert({'X', 10});
        values.insert({'V', 5});
        values.insert({'I', 1});
    }
    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {

            if (values[s[i]] < values[s[i + 1]])
            {
                ans -= values[s[i]];
            }
            else
            {
                ans += values[s[i]];
            }
        }
        return ans;
    }
};