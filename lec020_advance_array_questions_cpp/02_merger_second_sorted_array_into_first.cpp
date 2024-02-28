#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int size1, int size2) {
    int i = size1 - 1;  // Last index of arr1
    int j = size2 - 1;  // Last index of arr2
    int mergedIndex = size1 + size2 - 1;  // Last index of merged array

    // Merge the arrays in descending order
    while (j >= 0) {
        if (i >= 0 && arr1[i] > arr2[j]) {
            arr1[mergedIndex] = arr1[i];
            i--;
        } else {
            arr1[mergedIndex] = arr2[j];
            j--;
        }
        mergedIndex--;
    }
}

int main() {
    int arr1[6] = {3, 6, 9, 0, 0, 0};
    int arr2[3] = {4, 7, 10};

    int size1 = 3;  // Number of elements in arr1
    int size2 = 3;  // Number of elements in arr2

    mergeArrays(arr1, arr2, size1, size2);

    // Print the merged array
    for (int i = 0; i < size1 + size2; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}
