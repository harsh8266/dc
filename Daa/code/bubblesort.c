void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {2, 3, 6, 1, 3, 32, 2};
    int n = 7;

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}
