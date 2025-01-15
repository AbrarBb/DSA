#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) 
{
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        }

        if (arr[mid] < target) 
        {
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }

    return -1; 
}

int main() 
{
    vector<int> array = {11, 22, 30, 33, 40,66, 77, 80, 88, 99};
    int target = 88;

    cout << "Array size: " << array.size() << endl;

    int index = binarySearch(array, target);
    if (index == -1) 
    {
        cout << "Not found" << endl;
    } 
    else 
    {
        cout << "Found at index " << index+1 << endl;
    }

    return 0;
}
