#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>coins, int amount) 
{
    vector<int> dp(amount + 1, 1e9); //1e9=infinity 
    vector<int> lastCoin(amount + 1, -1);
    dp[0] = 0; 

    for (int coin : coins) 
    {
        for (int a = coin; a <= amount; a++) 
        {
            dp[a] = min(dp[a], dp[a - coin] + 1);
            lastCoin[a] = coin;
        }
    }
    
    
cout << "Coins needed: " << dp[amount] << "\nCoins used: ";
    for (int a = amount; a > 0; a -= lastCoin[a]) 
    {
        cout << lastCoin[a] << " ";
    }
    
    return dp[amount] == 1e9 ? -1 : dp[amount];
}

int main() 
{
    vector<int> coins = {2,1,5};
    int amount = 43;
    coinChange(coins, amount);
    //cout << coinChange(coins, amount) << endl; 
    return 0;
}
