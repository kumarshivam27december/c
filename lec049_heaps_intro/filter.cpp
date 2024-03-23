#include <stdio.h>

// Function to heapify a subtree rooted at given index
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Build a max heap from the array
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify all nodes in reverse order
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to filter elements based on the range [a, b]
int filterElements(int arr[], int n, int a, int b) {
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= a && arr[i] <= b) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    return newSize;
}

int main() {
    int N, a, b;
    scanf("%d", &N);
    int arr[N];

    // Input array elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Input range
    scanf("%d %d", &a, &b);

    // Build a max heap from the array
    buildMaxHeap(arr, N);

    // Filter elements based on the range and get the new size
    int newSize = filterElements(arr, N, a, b);

    // Rearrange the elements in the form of a Max Heap
    buildMaxHeap(arr, newSize);

    // Print the resulting array
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
