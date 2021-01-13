#include <stdio.h>
#include <stdbool.h>

void selectionSort(int arr[], int size);
void displayArray(int arr[], int size);

int main()
{
    int arr[] = {4, 6, 1, 3, 2, 7, 8, 9, 5, 10, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printf("Final sorted array:\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int arr[], int size)
{
    int i, j, pos, min;
    for (i = 0; i < size - 1; i++)
    {
        pos = i;
        min = arr[i];
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                pos = j;
            }
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
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