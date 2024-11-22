#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int arr[] = {5, 3, 8, 6, 2};
    int n = 5;

    sort(arr, arr + n);

    cout << "Binary Sort: ";
    for (int a = 0; a < n; a++) cout << arr[a] << " ";
    cout << endl;

    return 0;
}
