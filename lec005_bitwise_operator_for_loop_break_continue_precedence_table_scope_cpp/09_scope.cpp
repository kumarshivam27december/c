/*
In C++, the term "scope" refers to the region or context in a program where a variable, function, or other named entity is valid and can be accessed. It determines the visibility and lifetime of the entity. The scope rules in C++ help ensure that different entities can have unique names within a program and prevent naming conflicts.

There are several types of scopes in C++:

Global Scope: Entities declared outside of any function or class have global scope.
 They are accessible from anywhere in the program after their declaration.
 Global variables and functions have a lifetime throughout the entire program execution.

Local Scope: Entities declared within a block of code 
(such as a function, loop, or conditional statement) have local scope. 
They are only accessible within that block and any nested blocks. 
Local variables are created when the block is entered and 
destroyed when the block is exited.

Function Scope: Function parameters and variables declared within a function 
have function scope. They are accessible only within that function. 
Function parameters are created when the function is called and 
destroyed when the function returns. 
Local variables inside a function are created when the block is entered 
and destroyed when the block is exited.

Class Scope: Class members, including variables and functions, have class scope. 
They are accessible within the class and its member functions. 
Class variables have a lifetime as long as the class object exists.

Namespace Scope: Entities declared within a namespace have namespace scope. 
Namespaces provide a way to group related entities and avoid naming conflicts. 
The entities within a namespace can be accessed using the scope resolution operator (::).

It's important to note that entities with the same name 
can exist in different scopes without conflicts. 
In such cases, the entity with the narrowest scope takes precedence. 
For example, if a local variable and a global variable have the same name, 
the local variable will be used within its scope, 
overshadowing the global variable.


Understanding the scope rules in C++ is crucial for writing organized 
and maintainable code and for avoiding naming conflicts between different 
parts of a program.

*/

#include <iostream>
using namespace std;
int main()
{
    int a=3;
    cout<<a<<endl;
    if(true)
    {
        int b=1;
        cout<<b<<endl;
    }
    //cout<<b<<endl;////b is local scope

}