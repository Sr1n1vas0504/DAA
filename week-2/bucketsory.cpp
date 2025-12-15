//ch.sc.u4cse24146
#include <stdio.h>
#define N 10   // number of elements

// Insertion sort for individual buckets
void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    float arr[N] = {0.42, 0.32, 0.23, 0.52, 0.25,
                    0.47, 0.51, 0.11, 0.39, 0.28};

    int i, j;
    int bucketCount = N;

    // Buckets
    float bucket[N][N];
    int count[N] = {0};

    // Distribute elements into buckets
    for(i = 0; i < N; i++) {
        int index = bucketCount * arr[i];
        bucket[index][count[index]++] = arr[i];
    }

    // Sort each bucket
    for(i = 0; i < bucketCount; i++) {
        insertionSort(bucket[i], count[i]);
    }

    // Concatenate buckets
    int k = 0;
    for(i = 0; i < bucketCount; i++) {
        for(j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // Print sorted array
    printf("Sorted array:\n");
    for(i = 0; i < N; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}

