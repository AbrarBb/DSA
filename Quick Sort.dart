List<int> quickSort(List<int> arr) 
{
  if (arr.length <= 1) return arr;

  int pivot = arr[0];
  List<int> less = [];
  List<int> greater = [];

  for (var a = 1; a < arr.length; a++) 
  {
    if (arr[a] < pivot) 
    {
      less.add(arr[a]);
    } 
    else 
    {
      greater.add(arr[a]);
    }
  }

  return quickSort(less) + [pivot] + quickSort(greater);
}

void main() 
{
  List<int> numbers = [33, 11, 55, 22, 99, 44];
  print('Original List: $numbers');

  List<int> sortedNumbers = quickSort(numbers);
  print('Sorted List: $sortedNumbers');
}
