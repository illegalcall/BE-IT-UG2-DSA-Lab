#include <stdio.h>
#include <stdlib.h>

void heapSort(int arr[], int size);
void heapify(int arr[], int size, int index);

void displayArray(int arr[], int size);
void swap(int *a, int *b);

int main()
{
    int arr[] = {4, 6, 1, 3, 2, 7, 8, 9, 5, 10, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    printf("Final sorted array:\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void heapSort(int arr[], int size)
{
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
        displayArray(arr, size);
    }

    for (i = size - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
        displayArray(arr, size);
    }
}

void heapify(int arr[], int size, int index)
{
    int left = 2 * index + 1, right = 2 * index + 2, max_pos = index;
    if (left < size && arr[left] > arr[max_pos])
        max_pos = left;
    if (right < size && arr[right] > arr[max_pos])
        max_pos = right;
    if (max_pos != index)
    {
        swap(&arr[max_pos], &arr[index]);
        heapify(arr, size, max_pos);
    }
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