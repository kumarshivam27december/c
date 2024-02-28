#include <iostream>
#include <vector>
using namespace std;

void findDuplicates(int arr[], int size)
{
    bool foundDuplicate = false;

    // Iterate through each element in the array
    for (int i = 0; i < size - 1; i++) {
        // Check if the current element is a duplicate
        if (arr[i] != -1) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    // Found a duplicate
                    cout << arr[i] << " ";
                    arr[j] = -1; // Mark the duplicate element
                    foundDuplicate = true;
                }
            }
        }
    }

    // If no duplicates found, print a message
    if (!foundDuplicate) {
        cout << "No duplicates found";
    }

    cout << endl;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3, 2, 5, 6, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}
