/*
For deallocating the memory 
destructor is used
name->same as class
no return type
no input parameter


so it will be same as constructor as this
is also made auutomatically as the 
class is created 

so how can we differentiate between the
constructor and the destructor

so here in destructure tilda sign is used '~'

*/
#include <iostream>
#include <cstring>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;
    char *name;
    hero()
    {
        cout<<"default constructor called"<<endl;
        name = new char[100];
    }
    void print()
    {

        cout<<"health is :"<<health<<endl;
        cout<<"level is :"<<level<<endl;
        cout<<"name is :"<<name<<endl;
    }
    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }

    void sethealth(int h)
    {
        health=h;
    }
    void setlevel(char ch)
    {
        level = ch;
    }
    void setname(char name[])
    {
        strcpy(this->name,name);
    }

    //copy constructor
    hero(hero &temp)
    {
        cout<<"manual copy consttructor called"<<endl;
        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        this->health=temp.health;
        this->level=temp.level;

    }
    ~hero()
    {
        cout<<"destructor called"<<endl;
    }

};
int main()
{
    //static
    hero shivam; //killed by automatic destructor//
    //dynamic
    hero *ananya = new hero(); //killed by manually calling it
    delete ananya;
}