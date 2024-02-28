#include <iostream>

const int N = 3; // Size of the 2D array

void rotateMatrix(int mat[N][N]) {
    // Transpose the matrix
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Swap mat[i][j] and mat[j][i]
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // Reverse each row of the transposed matrix
    for (int i = 0; i < N; i++) {
        int start = 0;
        int end = N - 1;
        while (start < end) {
            // Swap mat[i][start] and mat[i][end]
            int temp = mat[i][start];
            mat[i][start] = mat[i][end];
            mat[i][end] = temp;
            start++;
            end--;
        }
    }
}

void displayMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int mat[N][N] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};

    std::cout << "Original Matrix:" << std::endl;
    displayMatrix(mat);

    rotateMatrix(mat);

    std::cout << "Matrix after 90 degree rotation:" << std::endl;
    displayMatrix(mat);

    return 0;
}
