#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size);
void displayArray(int arr[], int size);

int main()
{
    int arr[] = {4, 6, 1, 3, 2, 7, 8, 9, 5, 10, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printf("Final sorted array:\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                displayArray(arr, size);
            }
        }
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