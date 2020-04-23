#ifndef CC_H
#define CC_H

#include <bits/stdc++.h>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <ios>
#include <limits>
#include <string.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

template<class Iter, class T>
Iter binary_find(Iter begin, Iter end, T val)
{
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iter i = std::lower_bound(begin, end, val);

    if (i != end && !(val < *i))
        return i; // found
    else
        return end; // not found
}

void flushFileBuffer(){
    cin.ignore(std::numeric_limits<std::streamsize>::max());
}

void flushInputBuffer()
{
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void fastInt(int &number)
{

    bool negative = false;
    int c;

    number = 0;

    c = getchar();
    if (c == '-')
    {
    
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    if (negative)
        number *= -1;
}

inline int fast_atoi(char *&data)
{
    int val = 0;

    do
    {
        val = val * 10 + *data++ - '0';
    } while (*data & (1 << 4)); // '\n' doesn't have that bit

    ++data;
    return val;
}



#endif