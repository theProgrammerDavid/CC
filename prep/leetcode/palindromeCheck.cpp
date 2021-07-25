// https://leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(std::string &s)
{
    std::for_each(s.begin(), s.end(), [](char &ch)
                  { ch = toupper(ch); });

    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
        while (start < end and !isalnum(s[start]))
            start++;
        while (start < end and !isalnum(s[end]))
            end++;

        if (s[start] != s[end])
            return false;

        start++;
        end--;
    }

    return true;
}