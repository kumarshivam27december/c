/*
Const function: In C++, a const function 
is a member function of a class that 
guarantees not to modify the state of 
the object it is called on. 
You can declare a member function 
as const by adding the const keyword 
after the parameter list, 
both in the function declaration and defini tion.
 For example:

class MyClass {
public:
    void regularFunction(); // Non-const member function
    void constFunction() const; // Const member function
};

void MyClass::regularFunction() {
    // Implementation that can modify object state
}

void MyClass::constFunction() const {
    // Implementation that cannot modify object state
}
Const keyword in data member type: In C++, 
the const keyword can be used to declare a 
constant data member in a class. 
It indicates that the value of the 
data member cannot be modified once 
it is initialized. Here's an example:

class MyClass {
public:
    const int myConstant = 42; // Constant data member
};
Using const in object creation: 
You can create const objects in C++ 
by using the const keyword before 
the object name during declaration. 
Once a const object is created, 
its value cannot be modified. 
Here's an example:

class MyClass {
public:
    int myData;
};

int main() {
    const MyClass obj; // Creating a const object of MyClass
    obj.myData = 10; // Not allowed, as obj is const
    return 0;
}
Initialization list: Initialization lists 
are used in constructors of C++ classes to 
initialize the member variables. 
Instead of assigning values inside 
the constructor body, 
you can use an initializer list to 
initialize the member variables directly. 
This is often preferred, 
especially when dealing with 
const member variables or when you want to invoke
parameterized constructors of member objects. 
Here's an example:

class MyClass {
public:
    int myData;
    MyClass(int data) : myData(data) {
        // Constructor body
    }
};


*/