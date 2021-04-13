// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int inversionCount(long long arr[], long long N)
    {
        long long count = 0;
        for (long long i = 0; i < N - 1; i++)
        {
            for (long long j = i + 1; j < N; j++)
            {
                if (arr[i] > arr[j])
                    count++;
            }
        }

        return count;
    }
};

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends