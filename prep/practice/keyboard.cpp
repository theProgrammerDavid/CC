
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getPos(const char *s, int n, char c)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
                return i;
        }
        return -1;
    }

public:
    int calculateTime(const string &keyboard, const string &word)
    {
        int pos = 0;
        int count = 0;

        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];

            int np = getPos(keyboard.c_str(), keyboard.size(), c);
            count += (int)abs(pos - np);
            pos = np;
        }

        return count;
    }
};

int main()
{
    
    size_t T;
    Solution s;
    std::string keyboard, word;
    cin >> T;
    for (size_t i = 0; i < T; ++i)
    {
        cin >> keyboard >> word;
        cout << s.calculateTime(keyboard, word) << '\n';
    }
    return 0;
}