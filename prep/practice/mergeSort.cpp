#include <bits/stdc++.h>
using namespace std;

/**
 * MergeSort(A, low, high){
 * if low > high:
 *   return
 *  mid = (low + high)/2
 *  MergeSort(A, low, mid)
 *  MergeSort(A, mid+1, high)
 *  merge(A, low, mid, high)
 * }
 * */

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }
        k++;
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    int arr[] = {0, 2, 4, 6, 2, 5, 2, 56, 2, 21, -2, -5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    mergeSort(arr, 0, n - 1);
    print(arr, n);

    return 0;
}