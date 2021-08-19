#include <string>
#include <iostream>
using namespace std;

int minOps(string &s)
{
    char curr_char = 'A';
    size_t idx = 0;

    int total_time = 0;

    while (idx != s.size())
    {
        if (curr_char != s[idx])
        {
            int diff = abs(s[idx] - curr_char);
            if (diff <= abs(26 - diff))
            {
                total_time += diff;
            }
            else
            {
                total_time += (abs(26 - diff));
            }

            curr_char = s[idx];
        }

        idx++;
    }

    return total_time;
}

int main()
{
    string s;
    cin >> s;

    cout << minOps(s) << "\n";
}