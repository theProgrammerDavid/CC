#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    while (n)
    {
        int x;
        std::cin >> x;

        std::vector<std::string> vec(x);
        int state = 0;

        for (int i = 0; i < x; i++)
        {
            std::string x;
            std::cin >> x;
            vec.push_back(x);
        }

        for (auto i : vec)
        {
            if (i == "start")
            {
                state++;
            }

            if (i == "restart" && state == 0)
            {
                state++;
            }

            if (i == "stop")
            {
                if (state == 0)
                    state--;
                else
                    state = 0;
            }
        }
        std::cout << (state != 0 ? 404 : 200) << '\n';
        --n;
    }
    return 0;
}