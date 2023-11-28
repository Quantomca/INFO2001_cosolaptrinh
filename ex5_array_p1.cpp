#include <stdio.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start, end;
    double time_taken;

    start = clock();
    sortFunc(arr, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    return time_taken;
}

int main() {
    int arr[] = {1, 3, 4, 5, 6, 7, 9, 2, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang truoc khi sap xep: \n");
    printArray(arr, n);

    printf("\nMang sau khi sap xep bang Bubble Sort: \n");
    double bubbleTime = measureTime(bubbleSort, arr, n);
    printArray(arr, n);
    printf("Thoi gian thuc thi cua Bubble Sort: %f\n", bubbleTime);

    printf("\nMang sau khi sap xep bang Selection Sort: \n");
    double selectionTime = measureTime(selectionSort, arr, n);
    printArray(arr, n);
    printf("Thoi gian thuc thi cua Selection Sort: %f\n", selectionTime);

    return 0;
}

