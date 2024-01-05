int fibonacciSearch(long int arr[], int x, int n){
    int fibMm2 = 0;
    int fibMm1 = 1;
    int fibMm = fibMm2 + fibMm1;

    while (fibMm < n){
        fibMm2 = fibMm1;
        fibMm1 = fibMm;
        fibMm = fibMm2 + fibMm1;
    }

    int offset = -1;
    
    while (fibMm > 1){
        int i = std::min(offset + fibMm2, n - 1);

        if (arr[i] < x){
            fibMm = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibMm - fibMm1;
            offset = i;
        }
        else if (arr[i] > x){
            fibMm = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibMm - fibMm1;
        }
        else return i;
    }
    if (fibMm1 && arr[offset + 1] == x) return offset + 1;
    return -1;
}
