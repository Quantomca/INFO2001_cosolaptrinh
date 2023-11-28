#include <stdio.h>

int linearSearch(const int arr[], int n, int x, int *comparisonCount) {
    for (int i = 0; i < n; i++) {
        (*comparisonCount)++;
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const int arr[], int low, int high, int x, int *comparisonCount) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*comparisonCount)++;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int birany[] = {1, 10, 11, 100};
    int linear[] = {2, 4, 5, 6, 8};

    int x;
    printf("Nhap gia tri: ");
    scanf("%d", &x);

    int linearComparisons = 0;
    int linearIndex = linearSearch(linear, sizeof(linear) / sizeof(linear[0]), x, &linearComparisons);
    if (linearIndex != -1) {
        printf("Tim thay gia tri tuyen tinh. So lan so sanh: %d\n", linearComparisons);
    } else {
        printf("Khong tim thay gia tri tuyen tinh. So lan so sanh: %d\n", linearComparisons);
    }

    int binaryComparisons = 0;
    int biranyIndex = binarySearch(birany, 0, sizeof(birany) / sizeof(birany[0]) - 1, x, &binaryComparisons);
    if (biranyIndex != -1) {
        printf("Tim thay gia tri nhi phan. So lan so sanh: %d\n", binaryComparisons);
    } else {
        printf("Khong tim thay gia tri nhi phan. So lan so sanh: %d\n", binaryComparisons);
    }

    return 0;
}

