#include <stdio.h>
#include <stdlib.h>
/*
int binarySearch(int arraySize, int keyNumber, int array[]) {
    int start = 0;
    int end = arraySize - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(array[mid] == keyNumber) {
            return mid;
        } else if(keyNumber < array[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
} */

int *mergeSort(int array[], int size) {
    int divide = size / 2;
    int rightArraySize;
    if(size % 2 == 0) {
        rightArraySize = size / 2;
    } else {
        rightArraySize = size / 2 + 1;
    }
    if(divide == 1) {
        return;
    }
    int leftArray [divide];
    int rightArray [rightArraySize];
    for(int i = 0; i < divide; i++) {
        leftArray[i] = array[i];
    }
    for(divide; divide < size; divide++) {
        rightArray[divide] = array[divide];
    }
    leftArray = mergeSort(leftArray, divide);
    rightArray = mergeSort(rightArray, rightArraySize);
    merge(leftArray, rightArray, array, rightArraySize , divide);
    return array;
}

void merge(int leftArray[], int rightArray[], int array[], int rightSize, int leftSize) {
    int i = 0, j = 0, k = 0;
    while(i < leftSize && j < rightSize) {
        if(leftArray[i] > rightArray[j]) {
            array[k] = rightArray[j];
            j++;
        } else {
            array[k] = leftArray[i];
            i++;
        }
        k++;
    }
    while(i < leftSize) {
        array[k] = leftArray[i];
        k++;
        i++;
    }
    while(j < rightSize) {
        array[k] = rigtArray[j];
        k++;
        j++;
    }
}


int main()
{
    int array[] = {3, 5, 7, 1, 2, 8, 9, 4, 6};
    int size = sizeof(array) / sizeof(array[0]);
    mergeSort(array, size);
    for(i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
