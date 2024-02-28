#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;
    
    // Example vector
    vector<int> vec = {4, 7, 2, 1, 5};

    // Print the vector before deletion
    cout << "Vector before deletion: ";
    for (const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;

    // Element to be deleted
    int elementToDelete = 2;

    // Find the position of the element to delete
    auto iter = find(vec.begin(), vec.end(), elementToDelete);

    // Delete the element if found
    if (iter != vec.end()) {
        vec.erase(iter);
        cout << "Element " << elementToDelete << " deleted." << endl;
    } else {
        cout << "Element " << elementToDelete << " not found." << endl;
    }

    // Print the vector after deletion
    cout << "Vector after deletion: ";
    for (const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
