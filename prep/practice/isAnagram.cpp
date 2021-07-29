#include <bits/stdc++.h>
using namespace std;

bool isAnagram(const std::string &s1, const std::string &s2)
{
    if (s1.length() != s2.length())
        return false;
    int *letters = new int[256];
    int numChars = 0, numUniqueChars = 0;
    int numCompleted = 0;

    for (int i = 0; i < s1.length(); i++)
    {
        if (letters[(int)s1[i]] == 0)
            numUniqueChars++;
        letters[(int)s1[i]]++;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        int c = s2[i];
        if (letters[c] == 0)
            return false;
        //s1 doesnt have enough chars as that of s2
        letters[c]--;

        if (letters[c] == 0)
        {
            numCompleted++;
            if (numCompleted == numUniqueChars)
            {
                return i == s2.length() - 1;
            }
        }
    }
    return false;
}

bool isAnagramNaive(std::string s1, std::string s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1.compare(s2) == 0;
}

int main()
{
    assert(isAnagramNaive("LISTEN", "SILENT"));
    assert(isAnagramNaive("TRIANGLE", "INTEGRAL"));

    assert(isAnagram("LISTEN", "SILENT"));
    assert(isAnagram("TRIANGLE", "INTEGRAL"));
    return 0;
}