#include <iostream>
using namespace std;

// Define the custom heap class
class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int value) {
        size++;
        int index = size;
        arr[index] = value;
        // Compare and adjust the heap structure
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletion(int element) {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        int index = -1;
        for (int i = 1; i <= size; i++) {
            if (arr[i] == element) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Element not found" << endl;
            return;
        }
        arr[index] = arr[size];
        size--;
        int i = index;
        while (i <= size) {
            int lc = 2 * i;
            int rc = 2 * i + 1;
            if (lc < size && arr[i] < arr[lc] && arr[index] < arr[lc]) {
                swap(arr[lc], arr[i]);
                i = lc;
            } else if (rc <= size && arr[i] < arr[rc] && arr[index] < arr[rc]) {
                swap(arr[rc], arr[i]);
                i = rc;
            } else {
                return;
            }
        }
    }
};

// Define the heapify function
void heapify(int arr[], int size, int i) {
    int largest = i;
    int lc = 2 * i;
    int rc = 2 * i + 1;
    if (lc <= size && arr[largest] < arr[lc]) {
        largest = lc;
    }
    if (rc <= size && arr[largest] < arr[rc]) {
        largest = rc;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

// Define the heapsort function
void heapsort(int arr[], int size) {
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i >= 1; i--) {
        swap(arr[1], arr[i + 1]);
        heapify(arr, i, 1);
    }
}

int main() {
    // Creating an instance of the custom heap class
    heap maxHeap;

    // Insert elements into the heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(40);
    maxHeap.insert(50);

    // Print the heap
    maxHeap.print();

    // Deleting an element from the heap
    maxHeap.deletion(15);
    maxHeap.print();

    // Using heapify function
    int n;
    cin >> n;

    int arr[n + 1];  // Modified to have size n+1 to align with 1-based indexing
    for (int i = 1; i <= n; i++) { // Start from index 1 for 1-based indexing
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) { // Access elements from index 1 for 1-based indexing
        cout << arr[i] << " ";
    }
    cout << endl;
    // Using heapsort function
    heapsort(arr, n); // Use heapsort function directly

    // Print the sorted array
    for (int i = 1; i <= n; i++) { // Access elements from index 1 for 1-based indexing
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
