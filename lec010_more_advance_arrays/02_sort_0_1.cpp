#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(int arr[], int size) {
    int start = 0;   // Pointer for the leftmost 1
    int end = size - 1;   // Pointer for the rightmost 0

    while (start < end) {
        while (arr[start] == 0 && start < end) {
            start++;
        }
        while (arr[end] == 1 && start < end) {
            end--;
        }
        
        if (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
}

int main() {
    int arr[5] = {1, 0, 1, 0, 0};
    sortArray(arr, 5);
    printArray(arr, 5);
    return 0;
}
