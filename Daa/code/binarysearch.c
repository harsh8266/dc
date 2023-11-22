#include <stdio.h>

int binarysearch(int arr[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 32};
    int n = 6;
    int key = 5;
    int ans = binarysearch(arr, n, key);
    printf("%d", ans);

    return 0;
}