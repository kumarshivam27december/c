#include <iostream>
using namespace std;

int lastOccurence(int arr[], int start, int end, int key) {
    // base condition
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
        if (end == mid || arr[mid + 1] != key) {
            return mid;
        } else {
            // move to the right side
            return lastOccurence(arr, mid + 1, end, key);
        }
    }

    if (arr[mid] > key) {
        return lastOccurence(arr, start, mid - 1, key);
    }

    if (arr[mid] < key) {
        return lastOccurence(arr, mid + 1, end, key);
    }


    return 0;
}

int main() {
    int arr[8] = {1, 3, 5, 6, 6, 6, 9, 11};
    int key = 5;
    int ans = lastOccurence(arr, 0, 7, key);
    cout << ans << endl;
    return 0;
}
