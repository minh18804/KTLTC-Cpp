#include <bits/stdc++.h>
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "JumpSearch.h"
#include "TernarySearch.h"
#include "InterpolationSearch.h"
#include "FibonacciSearch.h"
#include "ExponentialSearch.h"

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

    auto start7 = high_resolution_clock::now();
    interpolationSearch(arr, 0, n-1, x);
    auto end7 = high_resolution_clock::now();

    auto time_elapsed1 = duration_cast<nanoseconds>(end1 - start1).count();
    auto time_elapsed2 = duration_cast<nanoseconds>(end2 - start2).count();
    auto time_elapsed3 = duration_cast<nanoseconds>(end3 - start3).count();
    auto time_elapsed4 = duration_cast<nanoseconds>(end4 - start4).count();
    auto time_elapsed5 = duration_cast<nanoseconds>(end5 - start5).count();
    auto time_elapsed6 = duration_cast<nanoseconds>(end6 - start6).count();
    auto time_elapsed7 = duration_cast<nanoseconds>(end7 - start7).count();

    std::cout << "Ket qua cua thuat toan Binary Search (Tim kiem nhi phan): Tim thay phan tu tai vi tri thu (" << binarySearch(arr, 0, n-1, x) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Jump Search (Tim kiem nhay): Tim thay phan tu tai vi tri thu (" << jumpSearch(arr, x, n) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Linear Search (Tim kiem tuyen tinh): Tim thay phan tu tai vi tri thu (" << linearSearch(arr, x, n) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Ternary Search (Tim kiem tam phan): Tim thay phan tu tai vi tri thu (" << ternarySearch(0, n-1, x, arr) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Fibonacci Search (Tim kiem Fibonacci): Tim thay phan tu tai vi tri thu (" << fibonacciSearch(arr, x, n-1) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Exponential Search (Tim kiem mu): Tim thay phan tu tai vi tri thu (" << exponentialSearch(arr, n-1, x) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Interpolation Search (Tim kiem noi suy): Tim thay phan tu tai vi tri thu (" << interpolationSearch(arr, 0, n-1, x) + 1 << ") trong mang" << std::endl;
    std::cout << std::endl;

    std::cout << "Thoi gian chay cua thuat toan Binary Search (Tim kiem nhi phan): " << time_elapsed1 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Jump Search (Tim kiem nhay): " << time_elapsed2 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Linear Search (Tim kiem tuyen tinh): " << time_elapsed3 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Ternary Search (Tim kiem tam phan): " << time_elapsed4 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Fibonacci Search (Tim kiem Fibonacci): " << time_elapsed5 << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Exponential Search (Tim kiem mu): " << time_elapsed6 << " nanoseconds" << std::endl;    
    std::cout << "Thoi gian chay cua thuat toan Interpolation Search (Tim kiem noi suy): " << time_elapsed7 << " nanoseconds" << std::endl;
    return 0;
}