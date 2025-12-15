//ch.sc.u4cse24146
#include <stdio.h>

// Function to perform Selection Sort on arr[]
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    // Move the boundary of the unsorted subarray one by one
    for (i = 0; i < n - 1; i++) {
        minIndex = i;  // Assume the first element is the minimum

        // Find the minimum element in unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element of unsorted part
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

