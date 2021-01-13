#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size);
void displayArray(int arr[], int size);

int main()
{
    int arr[] = {4, 6, 1, 3, 2, 7, 8, 9, 5, 10, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    printf("Final sorted array:\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            displayArray(arr, size);
        }
        arr[j + 1] = key;
        displayArray(arr, size);
    }
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