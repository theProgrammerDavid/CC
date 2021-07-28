#include <bits/stdc++.h>
using namespace std;

/**
 * returns index of first occured character
 * */
int isSubstring(const std::string &s1, const std::string &s2)
{
    int count = 0;
    int i = 0;
    for (; i < s1.length(); i++)
    {
        if (count == s2.length())
            break;

        if (s2[count] == s1[i])
        {
            count++;
        }
        else
        {
            if (count > 0)
                i -= count;
                // special edge case for duplicate characters
                //https://www.geeksforgeeks.org/check-string-substring-another/
            count = 0;
        }
    }

    if (count < s2.length())
        return -1;
    return i - count;
}

int main()
{
    const std::string s1 = "geeksfffffoorrfoorforgeeks";
    const std::string s2 = "for";

    cout << isSubstring(s1, s2) << "\n";
    return 0;
}