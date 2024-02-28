/*
3. Write a program in C to print the Fibonacci Series using recursion. >
Test Data :
Input number of terms for the Series (< 20) : 10
Expected Output:

 Input number of terms for the Series (< 20) : 10                                
 The Series are :                                                                
 1  1  2  3  5  8  13  21  34  55  
Click me to see the solution
*/

#include <iostream>
using namespace std;

void fibonacci(int n, int a = 0, int b = 1)
{
    if (n > 0) {
        cout << a << " ";
        fibonacci(n - 1, b, a + b);
    }
}

int main()
{
    int n;
    cout << "Input number of terms for the Series (< 20): ";
    cin >> n;

    cout << "The Series are: ";
    fibonacci(n);

    return 0;
}
