#include <iostream>

void findPairSum(int arr[], int size, int target) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                std::cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << target << std::endl;
            }
        }
    }
}

int main() {
    int arr[] = {2, 4, 1, 6, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    findPairSum(arr, size, target);

    return 0;
    
}
