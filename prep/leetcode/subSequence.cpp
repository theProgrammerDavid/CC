#include <bits/stdc++.h>
using namespace std;

/**
 * returns index of first occured character
 * Input: str1 = "AXY", str2 = "ADXCPY"
Output: True (str1 is a subsequence of str2)

Input: str1 = "AXY", str2 = "YADXCP"
Output: False (str1 is not a subsequence of str2)

Input: str1 = "gksrek", str2 = "geeksforgeeks"
Output: True (str1 is a subsequence of str2)
 * */
bool subSequence(const std::string &A, const std::string &B)
{
    int count = 0;
    int i = 0;

    for (; i < B.length(); i++)
    {
        if (A[count] == B[i])
            count++;
    }

    return count == A.length();
}

int main()
{
    cout << subSequence("AXY", "ADXCPY") << "\n";
    cout << subSequence("AXY", "YADXCP") << "\n";
    cout << subSequence("gksrek", "geeksforgeeks") << "\n";

    return 0;
}