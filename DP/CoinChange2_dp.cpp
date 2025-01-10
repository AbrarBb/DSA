#include <iostream>
#include <vector>
using namespace std;

void coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount + 1, 1e9), lastCoin(amount + 1, -1);
    dp[0] = 0;

    for (int coin : coins) 
    {
        for (int i = coin; i <= amount; ++i) 
        {
            if (dp[i - coin] + 1 < dp[i]) 
            {
                dp[i] = dp[i - coin] + 1;
                lastCoin[i] = coin;
            }
        }
    }

    if (dp[amount] == 1e9) 
    {
        cout << "Not possible to make the amount.\n";
        return;
    }

    cout << "Minimum coins needed: " << dp[amount] << "\nCoins used: ";
    for (int i = amount; i > 0; i -= lastCoin[i]) 
    {
        cout << lastCoin[i] << " ";
    }
    cout << endl;
}

int main() 
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    coinChange(coins, amount);
    return 0;
}
