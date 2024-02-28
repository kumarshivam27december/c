#include <iostream>
using namespace std;

void findIntersection(const int arr1[], int size1, const int arr2[], int size2)
{
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2

    cout << "Intersection: ";

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            j++;
        }
        else { // Found an intersection
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    cout << endl;
}

int main()
{
    int arr1[] = { 1, 2, 3, 4, 5, 6,11,46,68,89,90 };
    int arr2[] = { 3, 4, 5, 6, 7, 8,67,89,97 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    findIntersection(arr1, size1, arr2, size2);

    return 0;
}
