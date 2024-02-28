/*
    by defaul there is constructor present 
    while making class it automatically get invoked
    e.g.
        hero.ramesh();
    when we create it manually the automatic one get 
    deleted by own.
    //this is the manual way of creating a constructor
    hero()
    {

    }


    name is same as class
    no return type
    no input parameter

*/

#include <iostream>
using namespace std;
class hero{
    public:
    int health;
    char name[10];
    char level;
    hero()
    {
        cout<<"Constructor Called"<<endl;
    }
};
int main()
{
    cout<<"First system call"<<endl;
    //object creation statically
    hero ramesh;
    //object created dynamically
    hero *kamlesh = new hero();
    cout<<"last system call"<<endl;
    return 0;
}