#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int size);
void mergeArrays(int left[], int nL, int right[], int nR, int arr[]);
void displayArray(int arr[], int size);

int size;

int main()
{
    int arr[] = {4, 6, 1, 3, 2, 7, 8, 9, 5, 10, 2, 6};
    size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, size);
    printf("Final sorted array:\n");
    displayArray(arr, size);
}

void mergeSort(int arr[], int size)
{
    if (size < 2)
        return;

    int i, mid = size / 2, nL = mid, nR = size - mid;
    int *left = (int *)malloc(sizeof(int) * nL);
    int *right = (int *)malloc(sizeof(int) * nR);
    for (i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }
    mergeSort(left, nL);
    mergeSort(right, nR);
    mergeArrays(left, nL, right, nR, arr);
}

void mergeArrays(int *left, int nL, int *right, int nR, int arr[])
{
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < nL)
    {
        arr[k++] = left[i++];
    }
    while (j < nR)
    {
        arr[k++] = right[j++];
    }
}

void displayArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
