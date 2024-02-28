#include <iostream>
using namespace std;
int main() {
    int num = 10;
    float pi = 3.14;

    int* numPtr = &num;

    // Casting from int* to void*
    void* voidPtr = reinterpret_cast<void*>(numPtr);

    // Casting from void* to float*
    float* floatPtr = reinterpret_cast<float*>(voidPtr);

    // Accessing the value through the casted pointer
    cout << *floatPtr << endl; // Output: undefined behavior!

    return 0;
}
