#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array on the basis of a pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find pivot element such that
        // elements smaller than pivot are on the left
        // and elements greater than pivot are on the right
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the left and right subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array:\n";
    printArray(arr, size);

    return 0;
}
