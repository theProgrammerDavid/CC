// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the subarray with given sum k
    // arr: input array
    // n: size of array
    vector<int> subarraySum(int arr[], int n, int s)
    {

        // Your code here
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = arr[i];

            for (int j = i + 1; j <= n; j++)
            {
                if (sum == s)
                {
                    return {i, j-1};
                }

                if (sum > s || j == n)
                    break;
                sum += arr[j];
            }
        }
        return {0};
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends