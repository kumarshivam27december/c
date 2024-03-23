#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    // Example heap
    vector<int> heap = {4, 7, 2, 1, 5};
    
    // Print the heap before insertion
    cout << "Heap before insertion: ";
    for (const auto& element : heap) {
        cout << element << " ";
    }
    cout << endl;

    // Element to insert
    int elementToInsert = 3;

    // Insert the element in the heap
    heap.push_back(elementToInsert);
    push_heap(heap.begin(), heap.end());

    // Print the heap after insertion
    cout << "Heap after insertion: ";
    for (const auto& element : heap) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
