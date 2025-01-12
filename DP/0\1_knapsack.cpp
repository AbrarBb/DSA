#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) 
{
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int a = 0; a < n; a++) 
    {
        for (int w = capacity; w >= weights[a]; w--) 
        {
            dp[w] = max(dp[w], dp[w - weights[a]] + values[a]);
        }
    }

    return dp[capacity];
}

int main() 
{
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 8;

    cout << "Maximum value: " << knapsack(weights, values, capacity) << endl;

    return 0;
}
