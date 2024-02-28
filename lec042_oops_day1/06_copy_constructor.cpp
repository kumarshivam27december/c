/*
copy constructor 
-> object creation and copying the value 
by default it create an object after calling the copy constructor

*/
#include <iostream>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;
    void print()
    {
        cout<<"health is "<<health<<endl;
        cout<<"level is "<<level<<endl;
    }
    hero()
    {
        cout<<"Simple constructor is called"<<endl;
    }
    hero(int health)
    {
        this->health=health;
    }
    hero(int health,char level)
    {
        this->health=health;
        this->level=level;
    }
    //manual copy constructor
    hero(hero& temp)
    {
        cout<<"copy constructor is called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }
};
int main()
{
    //hero h1;
    hero ironman(1000,'A');
    ironman.print();
    // this is done as default 
    // and  if  we create a copy constructor manually
    //the default copy constructor get removed
    hero batman(ironman);
    batman.print();
    return 0;
}