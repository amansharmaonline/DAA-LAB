// searching_compare.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search
int linearSearch(int arr[], int n, int key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search (array must be sorted)
int binarySearch(int arr[], int n, int key, int *comparisons) {
    int left = 0, right = n - 1;
    while (left <= right) {
        (*comparisons)++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Simple Bubble Sort for sorting before binary search
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], arr_sorted[n];

    // Seed random number generator
    srand(time(NULL));
    printf("Randomly generated array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Copy array for sorting
    for (int i = 0; i < n; i++)
        arr_sorted[i] = arr[i];

    // Sort for binary search
    bubbleSort(arr_sorted, n);

    printf("Sorted array for Binary Search:\n");
    printArray(arr_sorted, n);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int comparisons = 0;
    clock_t start, end;
    double cpu_time_used;

    // Linear Search
    comparisons = 0;
    start = clock();
    int lin_idx = linearSearch(arr, n, key, &comparisons);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nLinear Search:\n");
    if (lin_idx != -1)
        printf("Element found at index %d\n", lin_idx);
    else
        printf("Element not found\n");
    printf("Comparisons: %d\n", comparisons);
    printf("Time taken: %f seconds\n", cpu_time_used);

    // Binary Search
    comparisons = 0;
    start = clock();
    int bin_idx = binarySearch(arr_sorted, n, key, &comparisons);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nBinary Search:\n");
    if (bin_idx != -1)
        printf("Element found at index %d\n", bin_idx);
    else
        printf("Element not found\n");
    printf("Comparisons: %d\n", comparisons);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
