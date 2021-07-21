#include <bits/stdc++.h>
using namespace std;

bool hasDupChars(const std::string &str)
{
    int check = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i] - 'a';
        if (check & (1 << val) > 0)
            return false;

        check |= 1 << val;
    }
    return true;
}

int main()
{
    std::string s1 = "hello world";
    std::string s2 = "abcdefg";

    std::cout << hasDupChars(s1) << '\n';
    std::cout << hasDupChars(s2) << '\n';

    return 0;
}