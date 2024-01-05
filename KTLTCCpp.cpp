#include <bits/stdc++.h>
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "JumpSearch.h"
#include "TernarySearch.h"
#include "InterpolationSearch.h"
#include "FibonacciSearch.h"
#include "ExponentialSearch.h"
int main(){
    using namespace std::chrono;
    int n;
    std::cout << "Nhap so phan tu cua mang de so sanh thuat toan: ";
    std::cin >> n;

    int times;
    std::cout << "Nhap so mang muon chay de so sanh thoi gian";
    std::cin >> times;

    int x;
    std::cout << "Nhap phan tu muon tim trong mang: ";
    std::cin >> x;

    auto end1 = high_resolution_clock::now();

    auto sum1 = duration_cast<nanoseconds>(end1 - end1).count();
    auto sum2 = duration_cast<nanoseconds>(end1 - end1).count();
    auto sum3 = duration_cast<nanoseconds>(end1 - end1).count();
    auto sum4 = duration_cast<nanoseconds>(end1 - end1).count();
    auto sum5 = duration_cast<nanoseconds>(end1 - end1).count();
    auto sum6 = duration_cast<nanoseconds>(end1 - end1).count();
    auto sum7 = duration_cast<nanoseconds>(end1 - end1).count();

    for(int j = 0; j < times; j++){
    long int arr[n];
    arr[0] = 0;
    srand(time(0));
    for(int i = 0; i < n; i++) arr[i] = arr[i - 1] + (rand() % (10 - 1 + 1) + 1);

    auto start1 = high_resolution_clock::now();
    binarySearch(arr, 0, n-1, arr[x]);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    jumpSearch(arr, arr[x], n);
    auto end2 = high_resolution_clock::now();

    auto start3 = high_resolution_clock::now();
    linearSearch(arr, arr[x], n);
    auto end3 = high_resolution_clock::now();

    auto start4 = high_resolution_clock::now();
    ternarySearch(0, n-1, arr[x], arr);
    auto end4 = high_resolution_clock::now();

    auto start5 = high_resolution_clock::now();
    fibonacciSearch(arr, arr[x], n-1);
    auto end5 = high_resolution_clock::now();

    auto start6 = high_resolution_clock::now();
    exponentialSearch(arr, n-1, arr[x]);
    auto end6 = high_resolution_clock::now();

    auto start7 = high_resolution_clock::now();
    interpolationSearch(arr, 0, n-1, arr[x]);
    auto end7 = high_resolution_clock::now();

    auto time_elapsed1 = duration_cast<nanoseconds>(end1 - start1).count();
    auto time_elapsed2 = duration_cast<nanoseconds>(end2 - start2).count();
    auto time_elapsed3 = duration_cast<nanoseconds>(end3 - start3).count();
    auto time_elapsed4 = duration_cast<nanoseconds>(end4 - start4).count();
    auto time_elapsed5 = duration_cast<nanoseconds>(end5 - start5).count();
    auto time_elapsed6 = duration_cast<nanoseconds>(end6 - start6).count();
    auto time_elapsed7 = duration_cast<nanoseconds>(end7 - start7).count();

    sum1 += time_elapsed1;
    sum2 += time_elapsed2;
    sum3 += time_elapsed3;
    sum4 += time_elapsed4;
    sum5 += time_elapsed5;
    sum6 += time_elapsed6;
    sum7 += time_elapsed7;

    std::cout << "Ket qua cua thuat toan Binary Search (Tim kiem nhi phan): Tim thay phan tu tai vi tri thu (" << binarySearch(arr, 0, n-1, arr[x]) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Jump Search (Tim kiem nhay): Tim thay phan tu tai vi tri thu (" << jumpSearch(arr, arr[x], n) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Linear Search (Tim kiem tuyen tinh): Tim thay phan tu tai vi tri thu (" << linearSearch(arr, arr[x], n) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Ternary Search (Tim kiem tam phan): Tim thay phan tu tai vi tri thu (" << ternarySearch(0, n-1, arr[x], arr) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Fibonacci Search (Tim kiem Fibonacci): Tim thay phan tu tai vi tri thu (" << fibonacciSearch(arr, arr[x], n-1) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Exponential Search (Tim kiem mu): Tim thay phan tu tai vi tri thu (" << exponentialSearch(arr, n-1, arr[x]) + 1 << ") trong mang" << std::endl;
    std::cout << "Ket qua cua thuat toan Interpolation Search (Tim kiem noi suy): Tim thay phan tu tai vi tri thu (" << interpolationSearch(arr, 0, n-1, arr[x]) + 1 << ") trong mang" << std::endl;
    std::cout << std::endl;
    }

    std::cout << "Thoi gian chay cua thuat toan Binary Search (Tim kiem nhi phan): " << sum1 / times << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Jump Search (Tim kiem nhay): " << sum2 / times << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Linear Search (Tim kiem tuyen tinh): " << sum3 / times << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Ternary Search (Tim kiem tam phan): " << sum4 / times << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Fibonacci Search (Tim kiem Fibonacci): " << sum5 / times << " nanoseconds" << std::endl;
    std::cout << "Thoi gian chay cua thuat toan Exponential Search (Tim kiem mu): " << sum6 / times << " nanoseconds" << std::endl;    
    std::cout << "Thoi gian chay cua thuat toan Interpolation Search (Tim kiem noi suy): " << sum7 / times << " nanoseconds" << std::endl;
    std::cout << std::endl;

    return 0;
}