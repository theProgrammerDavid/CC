#include <bits/stdc++.h>

using namespace std;

void insertionSort(int *arr, int n)
{
    int i = 0,
        j = 0,
        key = 0;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        
        char x[] = "lol";

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}

int main()
{
    int arr[] = {1, 2, 9, 34, 8, -2, 0, -3, 5, 7, -18};
    int n = 11;

    insertionSort(arr, n);
    return 0;
}