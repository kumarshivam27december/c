#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key) {
            return mid; // Return the index where key is found
        } else if (arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return 0; // Return -1 if key is not found
}

int main() {
    int arr[7] = {1, 3, 24, 56, 78, 96};
    int key = 3;

    int result = binarySearch(arr, 7, key);
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;
}
