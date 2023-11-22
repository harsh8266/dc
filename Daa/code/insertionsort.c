void insertionsort(int arr[], int n)
{
    int temp;
    int j;
    for (int i = 0; i < n; i++)
    {
        j = i;
        temp = arr[i];
        while (j > 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {2, 3, 6, 1, 3, 32, 2};
    int n = 7;

    insertionsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}