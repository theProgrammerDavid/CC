#include <bits/stdc++.h>

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        quicksort(arr, low, mid - 1);
        quicksort(arr, mid + 1, high);
    }
}

void print(int *a, int n)
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
    int n = sizeof(arr) / sizeof(int);
    print(arr, n);
    quicksort(arr, 0, n);
    print(arr, n);

    return 0;
}