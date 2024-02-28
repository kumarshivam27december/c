#include <iostream>
#include <vector>
#include <algorithm>

// Helper function to heapify a subarray rooted at given index
void heapify(std::vector<int>& arr, int size, int rootIndex)
{
    int largest = rootIndex; // Initialize the largest as root
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    // If left child is larger than root
    if (leftChild < size && arr[leftChild] > arr[largest])
        largest = leftChild;

    // If right child is larger than largest so far
    if (rightChild < size && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If largest is not root
    if (largest != rootIndex)
    {
        std::swap(arr[rootIndex], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// Main function to perform heap sort
void heapSort(std::vector<int>& arr)
{
    int size = arr.size();

    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Extract elements from heap one by one
    for (int i = size - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]); // Move the current root to the end

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    using namespace std;
    
    // Example usage
    vector<int> arr = {9, 5, 2, 7, 1, 3};
    
    cout << "Array before sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    
    heapSort(arr);
    
    cout << "Array after sorting: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
