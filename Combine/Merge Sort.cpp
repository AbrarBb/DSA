#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (int a = 0; a < n1; a++) L[a] = arr[left + a];
    for (int a = 0; a < n2; a++) R[a] = arr[mid + 1 + a];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() 
{
    int arr[] = {5, 3, 8, 6, 2};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    cout << "Merge Sort: ";
    for (int a = 0; a < n; a++) cout << arr[a] << " ";
    cout << endl;

    return 0;
}
