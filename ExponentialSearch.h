int exponentialSearch(int arr[], int n, int x) 
{ 

    if (arr[0] == x) 
        return 0; 
  
    int i = 1; 
    while (i < n && arr[i] <= x) 
        i *= 2; 
  
    return binarySearch(arr, i/2, std::min(i, n), x); 
} 
