/*
-------------------------
polymorphism-many form
papa-he is father,son,brother,husband
-------------------------
2 types
1. compile time polymorphism
2. run time polymorphism
-------------------------
compile time error
2 types
1.function overloaading
2.operator overloading
----------------------------
*/
#include <iostream>
using namespace std;
class A{
    public:
    void sayhello()
    {
        cout<<"hello shivam"<<endl;
    }
    /*
    int sayhello()
    {
        cout<<"hello shivam"<<endl;
    }
    */
    int sayhello(int m)
    {
        cout<<"hello shivam"<<endl;
        return 69;
    }
    void sayhello(char ch)
    {
        cout<<"hello shivam"<<endl;
    }
    void sayhello(string str)
    {
        cout<<"hello shivam"<<endl;
    }
};
int main()
{
    A obj;
    obj.sayhello(2);
    obj.sayhello('K');
    obj.sayhello();
    obj.sayhello("shivam");
          return 0;
}

/*


we can do like
int add(int a)
{
    return a;
}
int add(int a,int b)
{
    return a;
}
int add(int a,int b,int c)
{
    return a;
}
double add(double a,double b)
{

}

double add(int a,int b,int c=0,int d=0)
{

}
*/

/*compile time error



Compile time polymorphism Overview 
Compile time polymorphism is also known as static polymorphism. 
This type of polymorphism can be achieved through function 
overloading or operator overloading.


 a) Function overloading:When there are multiple
  functionsin a class with the same name
   but different parameters, these functions are overloaded. 
   The main advantage of function overloading is it
    increases the readability of the program.
     Functions can be overloaded by using
      different numbers of arguments and 
      by using different types of arguments.


i) Function overloading with different numbers of arguments: 
In this example, we have created two functions,
 the first add() performs the addition of the two 
 numbers, and the second add() performs the addition 
 of the three numbers. 
 
 Let’s look at the example: 
 #include <iostream> 
 using namespace std;
// Function with two parameters
 int add(int num1, int num2)
   { return num1 + num2; } 
   // Function with three parameters
    int add(int num1, int num2, int num3)
     { return num1 + num2 + num3; } 
     int main()
      { cout << add(10, 20) << endl;
       cout << add(10, 20, 30); 
       return 0; } 
       Output: 30 60 


       ii) Function overloading with different types of arguments:
    In this example, we have created two add() functions 
    with different data types. 
    The first add() takes two integer arguments
     and the second add() takes two double arguments. 


     #include <iostream>
    using namespace std;
    // Function with two integer parameters
    int add(int num1, int num2)
    { return num1 + num2; } 
    // Function with two double parameters
    double add(double num1, double num2)
    { return num1 + num2; }
    int main(void)
    { cout << add(10, 20) << endl;
    cout << add(10.4, 20.5); return 0; } 
    Output: 30 30.9 




Default Arguments:A default argument 
is a value providedin a function declaration 
automatically assigned by the compiler 
if the function’s caller doesn’t provide a 
value for 2the argument with a default value.
 However, if arguments are passed while calling the function, 
 the default arguments are ignored. 


 Example: A function with default arguments can be called 
 with 2  or 3 or 4 arguments.


  #include<iostream>
   using namespace std;
    int add(int x, int y, int z = 0, int w = 0)
     { return (x + y + z + w); }
      int main()
       { cout << add(10, 20) << endl;
        cout << add(10, 20, 30) << endl; 
        cout << add(10, 20, 30, 40) << endl; 
        return 0; 
        }



 Output: 30 60 100 
 
 
 
 b) Operator Overloading:C++ also provides options
 to overload operators. 
 For example, we can make the operator (‘+’) for 
 the string class to concatenate two strings. 
 We know that this is the addition operator whose 
 task is to add two operands. 
 A single operator, ‘+,’ when placed between integer operands, 
 adds them and concatenates them when placed 
 between string operands. 




 Points to remember while overloading an operator:
  ● It can be used only for user-defined 
  operators(objects, structures) but cannot be used for 
  in-built operators(int, char, float, etc.). 3


  ●Operators = and & are already overloaded in C++, 
  so we can avoid overloading them. 
  
  
  
  ● Precedence and associativity of operators remain intact. 
  List of operators that can be overloaded in C++: 
  List of operators that cannot be overloaded in C++:
Example:Perform the addition of two imaginary orcomplex numbers.



 #include<iostream> 
 using namespace std; 
 class Complex 
 { 
    private: 
    int real, imag; 
    public: 
    Complex(int r = 0, int i = 0) 
    { 
        real = r; imag = i;
    } 
    
    4// This is automatically called when '+' is used with 
    // between two Complex objects Complex operator + 
    (Complex const & b) 
    { 
        Complex a;
         a.real = real + b.real;
          a.imag = imag + b.imag;
           return a; 
           }
            void print()
             { 
                cout << real << " + i" << imag << endl;
                 }
                  };
                  
                  
                   int main() 
                   {
                     Complex c1(10, 5), c2(2, 4);
                      Complex c3 = c1 + c2;
                       // An example call to "operator+" 
                       c3.print(); 
                       }
                       
                       
                        Output: 12 + i9 5

*/


/*Run time polymorphism
The given code snippet is written in C++ and demonstrates 
the concept of inheritance and polymorphism.

The code begins by including the necessary libraries, 
in this case, "iostream".

The code defines a class called "Parent" with a 
single public member function called "show". 
Inside the "show" function, it outputs 
the text "Inside parent class" followed by a newline.

Two subclasses, "subclass1" and "subclass2", are defined. 
Both subclasses are publicly derived from the "Parent" class.

Each subclass overrides the "show" function from the parent class.
In the "subclass1" definition, 
the overridden function outputs the text "Inside subclass1" 
followed by a newline. In the "subclass2" definition, 
the overridden function outputs the text "Inside subclass2".

The "main" function is where the program execution starts. 
Within the "main" function, an object "o1" of type 
"subclass1" is created, followed by 
an object "o2" of type "subclass2".

The "show" function is called on both objects, 
invoking the respective overridden functions in each subclass.

Finally, the program outputs:

"Inside subclass1" followed by a newline 
(from the call to "o1.show()")
"Inside subclass2" (from the call to "o2.show()")
In summary, the code defines a parent class with two subclasses. 
The subclasses inherit the "show" function from 
the parent class and override it to provide their 
own implementations. 
The "main" function creates objects of the subclasses 
and calls the overridden functions, 
resulting in the respective outputs.





can you write the 
code 
Certainly! Here's the code snippet you provided:


#include <iostream>
using namespace std;

class Parent {
public:
    void show() {
        cout << "Inside parent class" << endl;
    }
};

class Subclass1: public Parent {
public:
    void show() {
        cout << "Inside subclass1" << endl;
    }
};

class Subclass2: public Parent {
public:
    void show() {
        cout << "Inside subclass2" << endl;
    }
};

int main() {
    Subclass1 o1;
    Subclass2 o2;

    o1.show();
    o2.show();

    return 0;
}
This code snippet demonstrates inheritance and polymorphism in C++. 
It includes the necessary libraries, 
defines the parent class Parent, 
and two subclasses Subclass1 and Subclass2. 
Each subclass overrides the show function from 
the parent class with its own implementation.

In the main function, 
objects of Subclass1 and Subclass2 are created. 
The show function is then called on these objects, 
which invokes the overridden versions of the
 function in each subclass.
  The program will output "Inside subclass1" followed 
  by a newline, and then "Inside subclass2" followed by a newline.

Note that it's important to include the
 necessary iostream header at the
  beginning of the code to use input/output functionality.


*/