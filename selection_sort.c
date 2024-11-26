#include <stdio.h>

void sortDescending(int arr[], int size) 
{
    for (int a = 0; a < size - 1; a++) 
    {
        int maxIndex = a;
        for (int b = a + 1; b < size; b++) 
        {
            if (arr[b] > arr[maxIndex]) 
            {
                maxIndex = b;
            }
        }
        if (maxIndex != a) 
        {
            int temp = arr[a];
            arr[a] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

void sortAscending(int arr[], int size) 
{
    for (int a = 0; a < size - 1; a++) 
    {
        int minIndex = a;
        for (int b = a + 1; b < size; b++) 
        {
            if (arr[b] < arr[minIndex]) 
            {
                minIndex = b;
            }
        }
        if (minIndex != a) 
        {
            int temp = arr[a];
            arr[a] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() 
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int a = 0; a < size; a++) 
    {
        printf("%d ", arr[a]);
    }
    printf("\n");

    sortDescending(arr, size);
    printf("Descending order: ");
    for (int a = 0; a < size; a++) 
    {
        printf("%d ", arr[a]);
    }
    printf("\n");

    sortAscending(arr, size);
    printf("Ascending order: ");
    for (int a = 0; a < size; a++) 
    {
        printf("%d ", arr[a]);
    }
    printf("\n");

    return 0;
}
