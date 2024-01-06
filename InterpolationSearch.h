int interpolationSearch(long int arr[], long int lo, long int hi, long int x) {
    unsigned int pos;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        else if(arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}
