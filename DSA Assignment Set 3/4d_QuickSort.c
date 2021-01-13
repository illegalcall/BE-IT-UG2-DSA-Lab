#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int start, int end);
int partitionIndex(int arr[], int start, int end);
void displayArray(int arr[], int size);
void swap(int *a, int *b);

int size;

int main()
{
    int arr[] = {4, 6, 1, 3, 2, 7, 8, 9, 5, 10, 2, 6};
    size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    printf("Final sorted array:\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int pIndex = partitionIndex(arr, start, end);
    quickSort(arr, start, pIndex - 1);
    quickSort(arr, pIndex + 1, end);

    displayArray(arr, size);
}

int partitionIndex(int arr[], int start, int end)
{
    int i, pIndex = start, pivot = arr[end];
    for (i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    int temp;
    swap(&arr[pIndex], &arr[end]);
    return pIndex;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void displayArray(int arr[], int size)
{
    printf("content of array after this iteration:\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}