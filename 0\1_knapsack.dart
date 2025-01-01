import 'dart:math';

void main() 
{
  List<int> weights = [2,3,4,5];
  List<int> values = [3,4,5,6];
  int capacity = 8;

  print("Maximum value: ${knapsack(weights, values, capacity)}");
}

int knapsack(List<int> weights, List<int> values, int capacity) 
{
  int n = weights.length;
  List<int> dp = List.filled(capacity + 1, 0); 

  for (int a = 0; a < n; a++) 
  {
    for (int w = capacity; w >= weights[a]; w--) 
    {
      dp[w] = max(dp[w], dp[w - weights[a]] + values[a]);
    }
  }

  return dp[capacity];
}
