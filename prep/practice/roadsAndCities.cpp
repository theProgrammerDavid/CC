#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B)
{
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> check;
    check.insert(0);
    int inversion = 0;
    vector<bool> visited(A.size(), 0);
    int count = 0;
    for (int traverse = 0; count < (int)A.size(); ++traverse)
    {
        for (int i = 0; i < (int)A.size(); ++i)
        {
            if (check.count(A[i]) > 0 && visited[i] == 0)
            {
                check.insert(B[i]);
                inversion++;
                swap(A[i], B[i]);
                visited[i] = 1;
                count++;
            }
            else if (check.count(B[i]) > 0 && visited[i] == 0)
            {
                check.insert(A[i]);
                visited[i] = 1;
                count++;
            }
        }
    }
    return inversion > 4 ? 2 * inversion : inversion;
}

int main()
{
    vector<int> v1 = {1, 1, 1, 9, 9, 9, 9, 7, 8};
    vector<int> v2 = {2, 0, 3, 1, 6, 5, 4, 0, 0};
    const int ans = solution(v1, v2);
    std::cout << ans << "\n";
}