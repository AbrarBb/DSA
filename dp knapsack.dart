import 'dart:math';
void main() {
  List<int> weights = [1,2,4,5];
  List<int> values = [5,4,8,6];
  int capacity = 5;

  var result = knapsack(weights, values, capacity);
  print("Maximum value: ${result['maxValue']}");
  print("Included items (1-based): ${result['items']}");
  print("DP Table:");
  printTable(result['dp']);
}

Map<String, dynamic> knapsack(List<int> weights, List<int> values, int capacity) 
{
  int n = weights.length;
  List<List<int>> dp = List.generate(n + 1, (_) => List.filled(capacity + 1, 0));

  for (int i = 1; i <= n; i++) 
  {
    for (int w = 1; w <= capacity; w++) 
    {
      if (weights[i - 1] <= w) 
      {
        dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }


  List<int> items = [];
  int remainingCapacity = capacity;
  for (int i = n; i > 0 && remainingCapacity > 0; i--) 
  {
    if (dp[i][remainingCapacity] != dp[i - 1][remainingCapacity]) 
    {
      items.add(i); 
      remainingCapacity -= weights[i - 1];
    }
  }

  return {'maxValue': dp[n][capacity], 'items': items.reversed.toList(), 'dp': dp};
}

void printTable(List<List<int>> dp) 
{
  for (var row in dp) 
  {
    print(row);
  }
}
