#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) 
        {
            if (arr[j] <= pivot) swap(arr[++i], arr[j]);
        }
        swap(arr[i + 1], arr[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

int main() 
{
    int arr[] = {5, 3, 8, 6, 2};
    int n = 5;

    quickSort(arr, 0, n - 1);

    cout << "Quick Sort: ";
    for (int a = 0; a < n; a++) cout << arr[a] << " ";
    cout << endl;

    return 0;
}
