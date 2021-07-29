/**
 * The Fibonacci numbers are the numbers in the following integer sequence.
 * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
 * */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull calFibDp(ull n)
{
    if (n == 0)
        return 0;

    ull arr[n + 2]; //edge cases,
    arr[0] = 0;
    arr[1] = 1;
    for (ull i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

ull calFib(ull n)
{
    if (n == 0)
        return 0;
    ull a = 0, b = 1, c = 0;
    for (ull i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    assert(calFib(9) == 34);
    assert(calFibDp(9) == 34);
}