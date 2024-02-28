/*

if two of func inherit from same parent and have same function name
to choose out from it we use scope resoluter operator


*/
#include <iostream>
using namespace std;
class A{
    public:
    void func()
    {
        cout<<"hi my name is Anmaanush"<<endl;
    }
};
class B{
    public:
    void func()
    {
        cout<<"hi my name is Banmanus"<<endl;
    }
};
class  C:public A,public B{

};
int main()
{
    C obj;
    obj.A::func(); 
    obj.B::func();
    return 0;
}