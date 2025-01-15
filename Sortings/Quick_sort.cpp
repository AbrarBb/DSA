#include <iostream>
#include <vector>
using namespace std;

vector<int> quickSort(const vector<int>& arr) 
{
    if (arr.size() <= 1) return arr;

    int pivot = arr[0];
    vector<int> less, greater;

    for (size_t a = 1; a < arr.size(); a++) 
    {
        if (arr[a] < pivot) 
        {
            less.push_back(arr[a]);
        } 
        else 
        {
            greater.push_back(arr[a]);
        }
    }

    vector<int> sortedLess = quickSort(less);
    vector<int> sortedGreater = quickSort(greater);


    sortedLess.push_back(pivot);
    sortedLess.insert(sortedLess.end(), sortedGreater.begin(), sortedGreater.end());

    return sortedLess;
}

int main() 
{
    vector<int> numbers = {33, 11, 55, 22, 99, 44};
    
    cout << "Original List: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    vector<int> sortedNumbers = quickSort(numbers);
    cout << "Sorted List: ";
    for (int num : sortedNumbers) cout << num << " ";


    return 0;
}
