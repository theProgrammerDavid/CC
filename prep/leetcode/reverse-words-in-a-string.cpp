// https://leetcode.com/problems/reverse-words-in-a-string-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseWords(vector<char> &s)
    {
        std::reverse(s.begin(), s.end());

        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                std::reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        reverse(s.begin() + start, s.end());
    }
};