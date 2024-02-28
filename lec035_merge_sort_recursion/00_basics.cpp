/*
Merge sort is defined as a sorting algorithm that works by dividing an array into smaller subarrays,
 sorting each subarray, and then merging the sorted subarrays back together to form the final sorted
  array.

In simple terms, we can say that the process of merge sort is to divide
 the array into two halves, sort each half, and then merge the sorted halves back together.
This process is repeated until the entire array is sorted.

Merge-Sort-Algorithm-(1)
Merge Sort Algorithm

How does Merge Sort work?
Merge sort is a recursive algorithm that continuously splits 
the array in half until it cannot be further divided i.e., 
the array has only one element left (an array with one element is always sorted). 
Then the sorted subarrays are merged into one sorted array.



See the below illustration to understand the working of merge sort.


Illustration:

Lets consider an array arr[] = {38, 27, 43, 10}

Initially divide the array into two equal halves:
Merge Sort: Divide the array into two halves
Merge Sort: Divide the array into two halves

These subarrays are further divided into two halves.
Now they become array of unit length that can no longer be divided and array of unit length 
are always sorted.
Merge Sort: Divide the subarrays into two halves (unit length subarrays here)
Merge Sort: Divide the subarrays into two halves (unit length subarrays here)

These sorted subarrays are merged together, and we get bigger sorted subarrays.

Merge Sort: Merge the unit length subarrys into sorted subarrays
Merge Sort: Merge the unit length subarrys into sorted subarrays

This merging process is continued until the sorted array is built from the smaller subarrays.

Merge Sort: Merge the sorted subarrys to get the sorted array
Merge Sort: Merge the sorted subarrys to get the sorted array

 
The following diagram shows the complete merge sort process for an example 
array {38, 27, 43, 3, 9, 82, 10}. 

Below is the Code implementation of Merge Sort.


// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;
 
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
 
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
Output
Given array is 
12 11 13 5 6 7 
Sorted array is 
5 6 7 11 12 13 
Complexity Analysis of Merge Sort:
Time Complexity: O(N log(N)),  
Merge Sort is a recursive algorithm and time complexity 
can be expressed as following recurrence relation. 

T(n) = 2T(n/2) + θ(n)

The above recurrence can be solved either using the Recurrence Tree method or the Master method. 
It falls in case II of the Master Method and the solution of the recurrence is θ(Nlog(N)). 
The time complexity of Merge Sort isθ(Nlog(N)) in all 3 cases (worst, average, and best) as 
merge sort always divides the array into two halves and takes linear time to merge two halves.

Auxiliary Space: O(N), In merge sort all elements are copied into an auxiliary array. 
So N auxiliary space is required for merge sort.

Applications of Merge Sort:
Sorting large datasets: Merge sort is particularly well-suited for sorting large datasets due to its 
guaranteed worst-case time complexity of O(n log n).

External sorting: Merge sort is commonly used in external sorting, 
where the data to be sorted is too large to fit into memory.


Custom sorting: Merge sort can be adapted to handle different input distributions, 
such as partially sorted, nearly sorted, or completely unsorted data.

Inversion Count Problem


Advantages of Merge Sort:
Stability: Merge sort is a stable sorting algorithm, 
which means it maintains the relative order of equal elements in the input array.


Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN), 
which means it performs well even on large datasets.

Parallelizable: Merge sort is a naturally parallelizable algorithm, 
which means it can be easily parallelized to take advantage of multiple processors or threads.


Drawbacks of Merge Sort:
Space complexity: Merge sort requires additional memory to store the merged sub-arrays 
during the sorting process. 

Not in-place: Merge sort is not an in-place sorting algorithm, 
which means it requires additional memory to store the sorted data. 
This can be a disadvantage in applications where memory usage is a concern.


Not always optimal for small datasets: 
For small datasets, Merge sort has a higher time complexity than some other sorting algorithms, 
such as insertion sort. This can result in slower performance for very small datasets.


*/