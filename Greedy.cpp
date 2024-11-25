#include <iostream>
using namespace std;

int coin[] = {10, 5, 2, 1};
int return_change(int amount)
 {
    if (amount < 0) return -1;

    int res = 0;
    int j = 0;
    int size = sizeof(coin) /sizeof(coin[0]);

    while (amount > 0) 
    {
        if (j >= size) return -1;
        if (amount >= coin[j]) 
        {
            amount -= coin[j];
            res++;
        }
        else
        {
            j++;
        }
    }
    return res;
}

int main() 
{
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    int result = return_change(amount);
    if (result == -1) 
    {
        cout << "The amount cannot be represented" << endl;
    } 
    else 
    {
        cout << "Minimum coins required: " << result << endl;
    }
    return 0;
}
