//File name: /Users/laptopuser/Documents/algorithms/mergesort.cpp
//source: https://onlinegdb.com/uY0ScrwpFn
#include <iostream>
#include <string>
using namespace std;

void mergeSort(int arr[], int size);
void merge(int arr[], int size);

int main() {
    int arr[] = {2, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, size);

    for (int elm: arr)
        cout << elm << " ";
    cout << endl;

    return 0;
}

void mergeSort(int arr[], int size) {
    //no need to sort if there is only zero or one element
    if (size <= 1)
       return;

    //size > 1
    mergeSort(arr, size/2); //first half
    mergeSort(arr + size/2, size - size/2); //second half
        //WARNING: size - size/2 is not the same as size / 2.
        //For example, when size is 3,
        //size / 2 returns 3 / 2, which is 1 due to integer division.
        //size - size /2 returns  3 - 3 / 2 = 3 - 1 = 2
    //merge sorted subarrays arr[i..j), which means the subarray
    //of elements from arr[i], arr[i+1], ..., arr[j-1]
    //arr[0..size/2) and arr[size/2 .. size),
    merge(arr, size); 
}

//add merge function
//(1) Denote subarray as arr[i..j) as a subset of elements of arr
//    from arr[i] (included) to the element right before arr[j],
//    that is, arr[i..j) contains elements
//    arr[i], arr[i+1], ..., arr[j-1]
//(2) Suppose arr[0..size/2) and arr[size/2..size) are both sorted.
//(3) Merge sorted arr[0..size/2) and arr[size/2..size) to get
//    a sorted array arr[0, size).
void merge(int arr[], int size) {
    int* brr = new int[size]; //temporary spaces to hold 
         //the sorted array with size many elements
    int k = 0; 
    int i = 0;
    int j = size/2;
    while (i < size / 2 && j < size) {
        if (arr[i] < arr[j]) {
           brr[k] = arr[i];
           k++;
           i++;
        }
        else {
            brr[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i < size / 2) {
        brr[k] = arr[i];
        i++;
        k++;
    }

    while (j < size) {
        brr[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i < size; i++) //i is a local variable
        arr[i] = brr[i];

    //release memory for brr
    delete[] brr;
    brr = nullptr;
}
