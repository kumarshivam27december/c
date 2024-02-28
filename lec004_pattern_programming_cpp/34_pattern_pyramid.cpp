/*

    1
   2 2
  3 3 3
 4 4 4 4


*/
#include <iostream>
using namespace std;


int main() {
    int rows = 4; // number of rows in the pyramid

    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int space = 1; space <= rows - i; space++) {
            cout << " "; // 2 spaces to maintain equal gap
        }

        // Print numbers
        for (int j = 1; j <= i; j++) {
            cout << i;
            // Print an extra space after the number, except for the last number in the row
            if (j < i) {
                cout << " "; // 2 spaces to maintain equal gap
            }
        }

        // Move to the next line after each row is printed
        cout << endl;
    }
    return 0;
}

