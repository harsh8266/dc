#include <stdio.h>

int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int left = low + 1;
    int right = high;

    while (left <= right)
    {
        while (left <= right && array[left] <= pivot)
        {
            left = left + 1;
        }
        while (left <= right && array[right] >= pivot)
        {
            right = right - 1;
        }
        if (left <= right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
        else
        {
            break;
        }
    }
    int temp = array[low];
    array[low] = array[right];
    array[right] = temp;

    return right;
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int p = partition(array, low, high);
        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }
}

int main()
{
    int data[] = {7, 4, 10, 8, 3, 1};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    quickSort(data, 0, size - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
