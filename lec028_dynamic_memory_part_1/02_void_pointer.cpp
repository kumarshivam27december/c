#include <iostream>
using namespace std;
int main() {
    int num = 10;
    float pi = 3.14;
    char letter = 'A';

    void* ptr;

    // Assigning the address of an integer to the void pointer
    ptr = &num;
    cout << "Value pointed to by the void pointer: " << *(static_cast<int*>(ptr)) << endl;

    // Assigning the address of a float to the void pointer
    ptr = &pi;
    cout << "Value pointed to by the void pointer: " << *(static_cast<float*>(ptr)) << endl;

    // Assigning the address of a char to the void pointer
    ptr = &letter;
    cout << "Value pointed to by the void pointer: " << *(static_cast<char*>(ptr)) << endl;

    return 0;
}
