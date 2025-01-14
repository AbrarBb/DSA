#include <stdio.h>

void sortDescending(int arr[], int size) 
{
    for (int a = 0; a < size; a++) 
    {
        for (int j = a + 1; j < size; j++) 
        {
            if (arr[a] < arr[j]) 
            {
                int temp = arr[a];
                arr[a] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void CoinChange(int amount, int coins[], int size) 
{
    for (int a = 0; a < size; a++) 
    { 
        int count = amount / coins[a];
        amount = amount % coins[a];  
        if (count > 0) 
        {  
        printf("%d X %d\n", coins[a], count);
        }
    }
}

int main() 
{
    int amount;
    int coins[] = {1, 2, 5, 10};
    int size = sizeof(coins) / sizeof(coins[0]);  

    printf("Enter Amount: ");
    scanf("%d", &amount);

    sortDescending(coins, size);  
    CoinChange(amount, coins, size);  

    return 0;
}
