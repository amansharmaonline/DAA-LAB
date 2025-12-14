#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort
    int bubbleSort(int arr[], int n) {
        int i, j, temp, swaps = 0;
        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swaps++;
                }
            }
        }
        return swaps;
}

// Improved Bubble Sort
int improvedBubbleSort(int arr[], int n) {
    int i, j, temp, swaps = 0;
    int swapped;
    for (i = 0; i < n-1; i++) {
        swapped = 0;  // reset before each pass
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
                swapped = 1;
            }
        }
        // If no elements were swapped in this pass, break
        if (swapped == 0)
            break;
    }
    return swaps;
}

// Insertion Sort
int insertionSort(int arr[], int n) {
    int i, key, j, swaps = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
            swaps++;
        }
        arr[j+1] = key;
    }
    return swaps;
}

// Selection Sort
int selectionSort(int arr[], int n) {
    int i, j, min_idx, temp, swaps = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }
    return swaps;
}

// Print array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Copy array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], arr_bubble[n], arr_improved_bubble[n], arr_insertion[n], arr_selection[n];

    // Seed random number generator
    srand(time(NULL));
    printf("Randomly generated array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Copy original array to all arrays
    copyArray(arr, arr_bubble, n);
    copyArray(arr, arr_improved_bubble, n);
    copyArray(arr, arr_insertion, n);
    copyArray(arr, arr_selection, n);

    int swaps;
    clock_t start, end;
    double cpu_time_used;

    // Bubble Sort
    start = clock();
    swaps = bubbleSort(arr_bubble, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array using Bubble Sort:\n");
    printArray(arr_bubble, n);
    printf("Number of swaps: %d\n", swaps);
    printf("Time taken: %f seconds\n", cpu_time_used);

    // Improved Bubble Sort
    start = clock();
    swaps = improvedBubbleSort(arr_improved_bubble, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array using Improved Bubble Sort:\n");
    printArray(arr_improved_bubble, n);
    printf("Number of swaps: %d\n", swaps);
    printf("Time taken: %f seconds\n", cpu_time_used);

    // Insertion Sort
    start = clock();
    swaps = insertionSort(arr_insertion, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array using Insertion Sort:\n");
    printArray(arr_insertion, n);
    printf("Number of swaps: %d\n", swaps);
    printf("Time taken: %f seconds\n", cpu_time_used);

    // Selection Sort
    start = clock();
    swaps = selectionSort(arr_selection, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array using Selection Sort:\n");
    printArray(arr_selection, n);
    printf("Number of swaps: %d\n", swaps);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
