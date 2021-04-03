#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;

    while (n)
    {
        std::string subs;
        std::cin >> subs;

        bool P = subs.find('P') != std::string::npos;
        bool C = subs.find('C') != std::string::npos;
        bool M = subs.find('M') != std::string::npos;

        std::cout << (P & C & M ? "YES\n" : "NO\n");

        --n;
    }
    return 0;
}