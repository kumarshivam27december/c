#include <iostream>
using namespace std;

void sortColors(int arr[], int n) {
    int low = 0;            // Pointer for 0s
    int high = n - 1;       // Pointer for 2s
    int mid = 0;            // Pointer for 1s

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    sortColors(arr, n);

    cout << "After sorting: ";
    printArray(arr, n);

    return 0;
}
