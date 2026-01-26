//CH.SC.U4CSE24146
#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    srand(time(NULL)); 
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    int pivot = arr[high]; 
    int i = low;           
    int j = high - 1;      
    while (i <= j) {
        while (i <= j && arr[i] < pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        
        if (i < j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    swap(&arr[i], &arr[high]);
    return i; 
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1); 
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int A[] = {157, 110, 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};
    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
