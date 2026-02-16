#include <stdio.h>

void mergeParts(int data[], int left, int mid, int right) {
    int a, b, c;
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int leftArr[size1], rightArr[size2];

    for (a = 0; a < size1; a++)
        leftArr[a] = data[left + a];
    for (b = 0; b < size2; b++)
        rightArr[b] = data[mid + 1 + b];

    a = 0;
    b = 0;
    c = left;

    while (a < size1 && b < size2) {
        if (leftArr[a] <= rightArr[b])
            data[c++] = leftArr[a++];
        else
            data[c++] = rightArr[b++];
    }

    while (a < size1)
        data[c++] = leftArr[a++];

    while (b < size2)
        data[c++] = rightArr[b++];
}

void divideSort(int data[], int left, int right) {
    int length = right - left + 1;
    if (length <= 1)
        return;

    if (length == 2) {
        if (data[left] > data[right]) {
            int tempVal = data[left];
            data[left] = data[right];
            data[right] = tempVal;
        }
        return;
    }

    int mid = left + (right - left) / 2;
    divideSort(data, left, mid);
    divideSort(data, mid + 1, right);
    mergeParts(data, left, mid, right);
}

int main() {
    int values[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int count = sizeof(values) / sizeof(values[0]);

    divideSort(values, 0, count - 1);

    printf("Sorted array: ");
    for (int i = 0; i < count; i++)
        printf("%d ", values[i]);

    return 0;
}

