/*
time to complete is such a property
that does neither depend on hero nor enemy  */
#include <iostream>
#include <cstring>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;
    char *name;
    static int timetocomplete;//doesnot depend on object independend of object
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
    //we initialise it outside of the class
    //doesnot depend on object
    int hero::timetocomplete = 5;
    /*
    syntax


    data_type class_name::fieldname_or_datamembername = value;


    we use scope resolutuon operator
    */
int main()
{
    hero shivam;
    cout<<"time to complete "<<hero::timetocomplete<<endl;


    cout<<"time to complete for shivam is  "<<shivam.timetocomplete<<endl;
    //but this above one is not recommended as it doesnot belong to object
    //rather it belong to class
    

    hero ananya;
    ananya.timetocomplete=2;
    cout<<"time to complete for shivam is "<<shivam.timetocomplete<<endl;
    cout<<"time to complete for ananya is "<<ananya.timetocomplete<<endl;
}