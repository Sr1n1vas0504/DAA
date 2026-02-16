#ch.sc.u4cse24146
#include <stdio.h>

void exchange(int *x, int *y) {
    int tempVal = *x;
    *x = *y;
    *y = tempVal;
}

int split(int data[], int start, int end) {
    int pivotVal = data[end];
    int index = start - 1;

    for (int k = start; k < end; k++) {
        if (data[k] < pivotVal) {
            index++;
            exchange(&data[index], &data[k]);
        }
    }

    exchange(&data[index + 1], &data[end]);
    return index + 1;
}

void sortQuick(int data[], int start, int end) {
    if (start < end) {
        int pivotIndex = split(data, start, end);
        sortQuick(data, start, pivotIndex - 1);
        sortQuick(data, pivotIndex + 1, end);
    }
}

int main() {
    int values[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int size = sizeof(values) / sizeof(values[0]);

    sortQuick(values, 0, size - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
    }

    return 0;
}

