#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount + 1, 1e9); 
    dp[0] = 0; 

    for (int coin : coins) 
    {
        for (int a = coin; a <= amount; ++a) 
        {
            dp[a] = min(dp[a], dp[a - coin] + 1);
        }
    }

    return dp[amount] == 1e9 ? -1 : dp[amount];
}

int main() 
{
    vector<int> coins = {1, 2, 5};
    int amount = 16;
    cout << coinChange(coins, amount) << endl; 
    return 0;
}