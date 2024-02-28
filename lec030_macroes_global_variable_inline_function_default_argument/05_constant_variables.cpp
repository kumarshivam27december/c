/*

Constant Variables:
There are a certain set of rules for the declaration and initialization of the constant variables:

The const variable cannot be left un-initialized at the time of the assignment.
It cannot be assigned value anywhere in the program.
Explicit value needed to be provided to the constant variable at the time of declaration of the constant variable.
const variable

Below is the C++ program to demonstrate the above concept:



// C++ program to demonstrate the
// the above concept
#include <iostream>
using namespace std;
 
// Driver Code
int main()
{
 
    // const int x;  CTE error
    // x = 9;   CTE error
    const int y = 10;
    cout << y;
 
    return 0;
}
Output: 
10
 

The error faced for faulty declaration: If you try to initialize the const variable without assigning an explicit value then a compile-time error (CTE) is generated. 



Const Keyword With Pointer Variables:
 Pointers can be declared with a const keyword. So, there are three possible ways to use a const keyword with a pointer, which are as follows:

When the pointer variable point to a const value:

Syntax: 

const data_type* var_name;
Below is the C++ program to implement the above concept: 


// C++ program to demonstrate the
// above concept
#include <iostream>
using namespace std;
 
// Driver Code
int main()
{
    int x{ 10 };
    char y{ 'M' };
 
    const int* i = &x;
    const char* j = &y;
 
    // Value of x and y can be altered,
    // they are not constant variables
    x = 9;
    y = 'A';
 
    // Change of constant values because,
    // i and j are pointing to const-int
    // & const-char type value
    // *i = 6;
    // *j = 7;
 
    cout << *i << " " << *j;
}
Output: 
9 A
 

Explanation: Here in the above case, i and j are two pointer variables that are pointing to a memory location const int-type and char-type, but the value stored at these corresponding locations can be changed as we have done above. 


Otherwise, the following error will appear: If we try to modify the value of the const variable.



When the const pointer variable point to the value:

Syntax:

data_type* const var_name;
Below is the example to demonstrate the above concept:


// C++ program to demonstrate the
// above concept
#include <iostream>
using namespace std;
 
// Driver Code
int main()
{
    // x and z non-const var
    int x = 5;
    int z = 6;
 
    // y and p non-const var
    char y = 'A';
    char p = 'C';
 
    // const pointer(i) pointing
    // to the var x's location
    int* const i = &x;
 
    // const pointer(j) pointing
    // to the var y's location
    char* const j = &y;
 
 
    // The values that is stored at the memory location can modified
    // even if we modify it through the pointer itself
    // No CTE error
    *i = 10;
    *j = 'D';
 
    // CTE because pointer variable
    // is const type so the address
    // pointed by the pointer variables
    // can't be changed
    // i = &z;
    // j = &p;
 
    cout << *i << " and " << *j
        << endl;
    cout << i << " and " << j;
 
    return 0;
}
Output:
10 and D
0x7ffe7b2392a0 and DC
Explanation: The values that are stored in the corresponding pointer variable i and j are modifiable, but the locations that are pointed out by const-pointer variables where the corresponding values of x and y are stored aren’t modifiable. 

Otherwise, the following error will appear: The pointer variables are const and pointing to the locations where the x and y are stored if we try to change the address location then we’ll face the error.



When const pointer pointing to a const variable:

Syntax:

const data_type* const var_name;
Below is the C++ program to demonstrate the above concept:


// C++ program to demonstrate
// the above concept
#include <iostream>
using namespace std;
 
// Driver code
int main()
{
    int x{ 9 };
 
    const int* const i = &x;
   
    // *i=10;  
    // The above statement will give CTE
    // Once Ptr(*i) value is
    // assigned, later it can't
    // be modified(Error)
 
    char y{ 'A' };
 
    const char* const j = &y;
   
    // *j='B';
    // The above statement will give CTE
    // Once Ptr(*j) value is
    // assigned, later it can't
    // be modified(Error)
 
    cout << *i << " and " << *j;
 
    return 0;
}
Output: 
9 and A
 

Explanation: Here, the const pointer variable points to the const variable. So, you are neither allowed to change the const pointer variable(*P) nor the value stored at the location pointed by that pointer variable(*P).

Otherwise, the following error will appear: Here both pointer variable and the locations pointed by the pointer variable are const so if any of them is modified, the following error will appear:



Pass const-argument value to a non-const parameter of a function cause error: Passing const argument value to a non-const parameter of a function isn’t valid it gives you a compile-time error.

Below is the C++ program to demonstrate the above concept:

// C++ program to demonstrate
// the above concept
#include <iostream>
using namespace std;
 
int foo(int* y)
{
    return *y;
}
 
// Driver code
int main()
{
    int z = 8;
    const int* x = &z;
    cout << foo(x);
    return 0;
}
Output: The compile-time error that will appear as if const value is passed to any non-const argument of the function then the following compile-time error will appear:



In nutshell, the above discussion can be concluded as follows:

1. int value = 5;         // non-const value

2. const int *ptr_1 = &value;      // ptr_1 points to a “const int” value, so this is a pointer to a const value.

3. int *const ptr_2 = &value;        // ptr_2 points to an “int”, so this is a const pointer to a non-const value.

4. const int *const ptr_3 = &value;   // ptr_3 points to a “const int” value, so this is a const pointer to a const value.



*/