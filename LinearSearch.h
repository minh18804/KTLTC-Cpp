int linearSearch(long int arr[], int target, int n) 
{
    for( int i = 0; i < n; i++ ) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}


