#include <bits/stdc++.h>

using namespace std;

void insertionSort(int *arr, int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;

        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout << '\n';
}

int main()
{
    int arr[] = {1, 2, 9, 34, 8, -2, 0, -3, 5, 7, -18};
    int n = 11;
    
    print(arr,n);
    
    insertionSort(arr, n);
    
    print(arr,n);
    return 0;
}