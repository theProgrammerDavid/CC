#include <bits/stdc++.h>
using namespace std;

void swap(const char *a, const char *b)
{
    const char *temp = a;
    a = b;
    b = temp;
}

void strRev(const char *str)
{
    int n = 0;

    while (str[n] != '\0')
    {
        n++;
    }

    if (n & 1)
    {
        // odd number of chars
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(&str[i], &str[n - i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    const char *s1 = "HelloWorld";

    std::cout << s1 << '\n';
    strRev(s1);
    std::cout << s1 << '\n';

    return 0;
}
