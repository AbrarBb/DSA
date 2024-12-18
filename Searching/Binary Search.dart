int binarySearch(List<int> arr, int target) 
{
  int left = 0, right = arr.length - 1;

  while (left <= right) 
  {
    int mid = (left + right) ~/ 2;
    
    if (arr[mid] == target) 
    {
      return mid; 
    }
    
    if (arr[mid] < target)
    {
      left = mid + 1; 
    }
    
    else right = mid - 1; 
  }

  return -1; 
}

void main() 
{
  var array = [11,22,30,33,40,44,55,60,66,77,80,88,99];
  //array.sort();
  int target = 88;
  print(array.length);

  int index = binarySearch(array, target);
  print(index == -1 ? 'Not found' : 'Found at index $index');
}
