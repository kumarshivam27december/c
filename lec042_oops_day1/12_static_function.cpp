/*
we need not need create object here as well we only need class
therefore we are not using this keyword 
as this keyword is pointer to current object and 
there is no object
 
it can access only static data member

 
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
    static int timetocomplete;
    static int random()
    {
        //cout<<this->health<<this->level<<health<<level<<name;
        //it wont give any of these things it will 
        //only give which is static data member
        return timetocomplete;
    }
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
    ~hero()
    {
        cout<<"destructor called"<<endl;
    }

};
int hero::timetocomplete = 5;
int main()
{
    hero shivam;
    cout<<hero::timetocomplete<<endl;
    cout<<hero::random()<<endl;
}