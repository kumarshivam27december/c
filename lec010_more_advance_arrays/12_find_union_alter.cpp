#include <iostream>
using namespace std;

void findUnion(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0;  // Index for arr1
    int j = 0;  // Index for arr2

    // Traverse both arrays
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else // arr1[i] == arr2[j]
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    // Print remaining elements of the larger array
    while (i < size1)
    {
        cout << arr1[i] << " ";
        i++;
    }

    while (j < size2)
    {
        cout << arr2[j] << " ";
        j++;
    }
}

int main()
{
    int a1[] = {1, 2, 3};
    int a2[] = {2, 3, 4, 5};

    int size1 = sizeof(a1) / sizeof(a1[0]);
    int size2 = sizeof(a2) / sizeof(a2[0]);

    findUnion(a1, size1, a2, size2);

    return 0;
}
