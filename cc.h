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

template <class T>
T slice(vector<T> vec, size_t start, size_t end)
{
    vector<T>::const_iterator first = vec.begin() + start;
    vector<T>::const_iterator last = vec.begin() + end;
    return vector<T> newVec(first, last);
}

vector<string> split_string(const string &line)
{
    stringstream ss(line);
    vector<string> tokens{istream_iterator<string>{ss}, istream_iterator<string>{}};
    return tokens;
}

template <class Iter, class T>
Iter binary_find(Iter begin, Iter end, T val)
{
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iter i = std::lower_bound(begin, end, val);

    if (i != end && !(val < *i))
        return i; // found
    else
        return end; // not found
}

void fbflush()
{
    cin.ignore(std::numeric_limits<std::streamsize>::max());
}

void ibflush()
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
template <class T>
void printVector(vector<T> &vec)
{

    cout << "\n";

    for (T x : vec)
    {
        cout << x << " ";
    }
    cout << "\n";
}

template <class T>
void printVector(vector<T> &vec, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
}
#endif