#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) 
{
    vector<int> temp; 
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp.push_back(arr[i++]);
        } 
        else 
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) 
    {
        temp.push_back(arr[i++]);
    }


    while (j <= right) 
    {
        temp.push_back(arr[j++]);
    }

    for (int k = 0; k < temp.size(); k++) 
    {
        arr[left + k] = temp[k];
    }
}


void mergeSort(vector<int>& arr, int left, int right) 
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
    vector<int> arr = {33, 11, 55, 22, 99, 44};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
