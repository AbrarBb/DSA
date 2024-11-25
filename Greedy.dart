void coinChange(int amount) 
{
  List<int> coins = [2,1,5,10]; 
  // Sort in descending order
  coins.sort((b, a) => a.compareTo(b));

  for (int coin in coins) 
  {
    int count = amount ~/ coin;
    amount = amount - (coin * count); 
    if (count > 0) 
    {
      print("$coin x $count");
    }
  }
}

void main() 
{
  int amount = 87;
  coinChange(amount);
}
