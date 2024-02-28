/*
more than 1 type of inheritance make hybrid


*/
#include <iostream>
using namespace std;
/*
class A{
    public:
    void funcA()
    {
        cout<<"inside function A";
    }


};
class B:public A{
    public:
    void funcB()
    {
        cout<<"inside function B";
    }
};
class C:public B,public A{
    public:
    void funcC()
    {
        cout<<"inside function C";
    }
};
int main()
{
    A a;
    a.funcA();
    B b;
    b.funcA();
    b.funcB();
    C c;
    c.funcB();
    c.funcC();
    ////c.funcA();
}
*/
/*
Apologies for the confusion in my previous response. 
The error in the last line is likely due to the fact 
that when class C inherits from class B and class A, 
it creates two copies of class A within class C.
 This is known as the "diamond problem" in multiple inheritance.

In the given code, both class B and class C
 inherit from class A, which creates ambiguity
  when accessing the member functions and attributes 
  of class A through the object c.
   This ambiguity leads to a compilation error.

To resolve this error, 
you can use virtual inheritance.
 By using the virtual keyword while 
 inheriting from class A, 
 you can ensure that only one instance of class A
  is created within class C.
   Here's an example of how the code 
   can be modified to avoid the error:


*/



class A {
public:
    void funcA() {
        cout << "inside function A\n";
    }
};

class B : virtual public A {
public:
    void funcB() {
        cout << "inside function B\n";
    }
};

class C : virtual public A,virtual public B {
public:
    void funcC() {
        cout << "inside function C\n";
    }
};

int main() {
    C c;
    c.funcA();
    c.funcB();
    c.funcC();
}

