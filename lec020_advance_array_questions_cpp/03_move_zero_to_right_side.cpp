#include <iostream>
using namespace std;

void moveZeroes(int arr[], int size) {
    int nonZeroIndex = 0;

    // Move all the non-zero elements to the left side
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            // arr[nonZeroIndex] = arr[i];
            swap(arr[i],arr[nonZeroIndex]);
            nonZeroIndex++;
        }
    }

    // Fill the remaining elements with zeroes
    while (nonZeroIndex < size) {
        arr[nonZeroIndex] = 0;
        nonZeroIndex++;
    }
}

int main() {
    int arr[] = {2, 0, 1, 0, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, size);

    // Print the modified array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
