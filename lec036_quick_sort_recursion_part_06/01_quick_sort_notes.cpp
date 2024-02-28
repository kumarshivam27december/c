/*


QuickSort is a sorting algorithm based on the Divide and Conquer algorithm 
that picks an element as a pivot and partitions the given array around the 
picked pivot by placing the pivot in its correct position in the sorted array.



How does QuickSort work?
The key process in quickSort is a partition(). 
The target of partitions is to place the pivot (any element can be chosen to be a pivot) 
at its correct position in the sorted array and put all smaller elements to the left of the pivot, 
and all greater elements to the right of the pivot.

Partition is done recursively on each side of the pivot after the pivot 
is placed in its correct position and this finally sorts the array.


How Quicksort works

Choice of Pivot:
There are many different choices for picking pivots. 

Always pick the first element as a pivot.
Always pick the last element as a pivot (implemented below)
Pick a random element as a pivot.
Pick the middle as the pivot.



Partition Algorithm:
The logic is simple, we start from the leftmost element and 
keep track of the index of smaller (or equal) elements as i. 
While traversing, if we find a smaller element, 
we swap the current element with arr[i]. Otherwise, we ignore the current element.

Let us understand the working of partition and the Quick Sort 
algorithm with the help of the following example:

Consider: arr[] = {10, 80, 30, 90, 40}.

Compare 10 with the pivot and as it is less than pivot arrange it accrodingly.
Partition in QuickSort: Compare pivot with 10
Partition in QuickSort: Compare pivot with 10

Compare 80 with the pivot. It is greater than pivot.
Partition in QuickSort: Compare pivot with 80
Partition in QuickSort: Compare pivot with 80

Compare 30 with pivot. It is less than pivot so arrange it accordingly.
Partition in QuickSort: Compare pivot with 30
Partition in QuickSort: Compare pivot with 30

Compare 90 with the pivot. It is greater than the pivot.
Partition in QuickSort: Compare pivot with 90
Partition in QuickSort: Compare pivot with 90

Arrange the pivot in its correct position.
Partition in QuickSort: Place pivot in its correct position
Partition in QuickSort: Place pivot in its correct position

Illustration of Quicksort:
As the partition process is done recursively, 
it keeps on putting the pivot in its actual position in the sorted array. 
Repeatedly putting pivots in their actual position makes the array sorted.



Code implementation of the Quick Sort:
Below is the implementation of the Quicksort:


// C++ code to implement quicksort
 
#include <bits/stdc++.h>
using namespace std;
 
// This function takes last element as pivot,
// places the pivot element at its correct position
// in sorted array, and places all smaller to left
// of pivot and all greater elements to right of pivot
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
 
            // Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
// Driver Code
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    quickSort(arr, 0, N - 1);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    return 0;
}
Output
Sorted array: 
1 5 7 8 9 10 


Complexity Analysis of Quick Sort:
Time Complexity:

Best Case: \omega (N * log N)   
Average Case: \Theta (N * logN)   
Worst Case: O(N2)
Auxiliary Space: O(1) we don’t consider the recursive stack space. 
If we consider the recursive stack space then, 
in the worst case quicksort could make O(N) nested recursive calls 
and will need O(N) auxiliary space.



Advantages of Quick Sort:


It is a divide-and-conquer algorithm that makes it easier to solve problems.
It is efficient on large data sets.
It has a low overhead, as it only requires a small amount of memory to function.


Disadvantages of Quick Sort:


It has a worst-case time complexity of O(N2), which occurs when the pivot is chosen poorly.

It is not a good choice for small data sets.

It is not a stable sort, meaning that if two elements have the same key, 
their relative order will not be preserved in the sorted output in case of quick sort, 
because here we are swapping elements 
according to the pivot’s position (without considering their original positions).




*/