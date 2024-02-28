#include <iostream>
using namespace std;

// Function to check if it is possible to allocate books within a maximum limit
bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            return false;
        }

        if (pagesSum + arr[i] <= mid) {
            pagesSum += arr[i];
        } else {
            studentCount++;
            pagesSum = arr[i];

            if (studentCount > m) {
                return false;
            }
        }
    }

    return true;
}

// Function to allocate books to students
int allocateBooks(int arr[], int n, int m) {
    if (n < m) {
        return -1;  // Not enough books for each student
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int start = 0;
    int end = sum;
    int result = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return result;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2;

    int result = allocateBooks(arr, n, m);

    if (result == -1) {
        cout << "Not enough books for each student" << endl;
    } else {
        cout << "Minimum number of pages a student needs to read: " << result << endl;
    }

    return 0;
}
