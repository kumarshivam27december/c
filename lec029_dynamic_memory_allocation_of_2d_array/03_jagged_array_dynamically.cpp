/*

////this is a wrong method

#include <iostream>

int main() {
    // Create a dynamic jagged array
    int** jaggedArray;
    int rows = 3;

    jaggedArray = new int*[rows]; // Create the outer array with 'rows' number of elements

    // Set the size of each inner array
    jaggedArray[0] = new int[5]; // First inner array with 5 elements
    jaggedArray[1] = new int[3]; // Second inner array with 3 elements
    jaggedArray[2] = new int[4]; // Third inner array with 4 elements

    // Access and modify elements of the jagged array
    jaggedArray[0][0] = 1;
    jaggedArray[0][1] = 2;
    jaggedArray[1][0] = 3;
    jaggedArray[2][2] = 4;

    // Print the elements of the jagged array
    int sizes[] = { 5, 3, 4 }; // Sizes of the inner arrays

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            std::cout << jaggedArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] jaggedArray[i]; // Deallocate each inner array
    }
    delete[] jaggedArray; // Deallocate the outer array

    return 0;
}


*/
