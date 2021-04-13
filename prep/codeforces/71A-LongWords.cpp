#include <iostream>
#include <string>
using namespace std;

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;

        if (s.size() > 10)
        {
            // cout << s[0] << s.substr(1, s.size() - 1) << s[s.size() - 1] << "\n";
            cout << s[0] << s.substr(1, s.size() - 1).size()-1 << s[s.size() - 1] << "\n";

        }
        else
        {
            cout << s << "\n";
        }
    }
    return 0;
}