#include <iostream>
using namespace std;
void findTripletSum(int arr[], int size, int target) {
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (arr[i] + arr[j] + arr[k] == target) {
                    cout << "Triplet found: " << arr[i] << " + " << arr[j] << " + " << arr[k] << " = " << target << endl;
                }
            }
        }
    }
}

int main() {
    int arr[] = {2, 4, 1, 6, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    findTripletSum(arr, size, target);

    return 0;
}
