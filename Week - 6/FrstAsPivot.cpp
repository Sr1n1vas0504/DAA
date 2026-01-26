//CH.SC.U4CSE24146
#include <stdio.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // first element
    int i = low;
    int j = high;
    while (i<j) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        
        if (i < j){
        swap(&arr[i], &arr[j]);
		}
	}    
	swap(&arr[low],&arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int A[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
