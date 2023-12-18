#include <bits/stdc++.h>
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}


int jumpSearch(int arr[], int x, int n) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[std::min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    while (arr[prev] < x) {
        prev++;
        if (prev == std::min(step, n))
            return -1;
    }
    if (arr[prev] == x)
        return prev;

    return -1;
}

int linearSearch(int arr[], int target, int n) 
{
    for( int i = 0; i < n; i++ ) {
        if ( arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int ternarySearch(int l, int r, int key, int ar[]) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
        if (key < ar[mid1]) {
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else {
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }
    return -1;
}

int fibonacciSearch(int arr[], int x, int n){
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
    if (fibMm1 && arr[offset + 1 == x]) return offset + 1;
}

int exponentialSearch(int arr[], int n, int x) 
{ 

    if (arr[0] == x) 
        return 0; 
  
    int i = 1; 
    while (i < n && arr[i] <= x) 
        i = i*2; 
  
    return binarySearch(arr, i/2, std::min(i, n), x); 
} 

int main() {
    using namespace std::chrono;
    int n;
    std::cout << "Nhap so phan tu cua mang de so sanh thuat toan: ";
    std::cin >> n;
    int x;
    std::cout << "Nhap phan tu muon tim trong mang: ";
    std::cin>>x;
	int arr[n];
	for(int i=0; i<n; i++) arr[i]=i;
    auto start1 = high_resolution_clock::now();
    binarySearch(arr, 0, n-1, x);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    jumpSearch(arr, x, n);
    auto end2 = high_resolution_clock::now();

    auto start3 = high_resolution_clock::now();
    linearSearch(arr, x, n);
    auto end3 = high_resolution_clock::now();

    auto start4 = high_resolution_clock::now();
    ternarySearch(0, n-1, x, arr);
    auto end4 = high_resolution_clock::now();

    auto start5 = high_resolution_clock::now();
    fibonacciSearch(arr, x, n-1);
    auto end5 = high_resolution_clock::now();

    auto start6 = high_resolution_clock::now();
    exponentialSearch(arr, n-1, x);
    auto end6 = high_resolution_clock::now();

    auto time_elapsed1 = duration_cast<nanoseconds>(end1 - start1).count();
    auto time_elapsed2 = duration_cast<nanoseconds>(end2 - start2).count();
    auto time_elapsed3 = duration_cast<nanoseconds>(end3 - start3).count();
    auto time_elapsed4 = duration_cast<nanoseconds>(end4 - start4).count();
    auto time_elapsed5 = duration_cast<nanoseconds>(end5 - start5).count();
    auto time_elapsed6 = duration_cast<nanoseconds>(end6 - start6).count();

    std::cout << "Ket qua cua thuat toan Binary Search: " << binarySearch(arr, 0, n-1, x) << std::endl;
    std::cout << "Ket qua cua thuat toan Jump Search: " << jumpSearch(arr, x, n) << std::endl;
    std::cout << "Ket qua cua thuat toan Linear Search: " << linearSearch(arr, x, n) << std::endl;
    std::cout << "Ket qua cua thuat toan Ternary Search: " << ternarySearch(0, n-1, x, arr) << std::endl;
    std::cout << "Ket qua cua thuat toan Fibonacci Search: " << fibonacciSearch(arr, x, n-1) << std::endl;
    std::cout << "Ket qua cua thuat toan Exponential Search: " << exponentialSearch(arr, n-1, x) << std::endl;

    std::cout << "Thoi gian chay cua thuat toan Binary Search: " << time_elapsed1 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Jump Search: " << time_elapsed2 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Linear Search: " << time_elapsed3 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Ternary Search: " << time_elapsed4 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Fibonacci Search: " << time_elapsed5 << "nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Exponential Search: " << time_elapsed6 << "nanoseconds" << std::endl;    
    return 0;
}