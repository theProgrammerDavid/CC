#include <bits/stdc++.h>

using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int size)
{
    int temp[size];
    return _mergeSort(arr, temp, 0, size - 1);
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        count += _mergeSort(arr, temp, left, mid);
        count += _mergeSort(arr, temp, mid + 1, right);

        // merge the two arrays together
        count += merge(arr, temp, left, right, mid + 1, right);
        return count;
    }
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int count = 0;

    i = left;
    j = mid;
    k = left;
}