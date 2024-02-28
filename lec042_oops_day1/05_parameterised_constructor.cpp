/*
This is a pointer to the current object
*/

#include <iostream>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;
    int gethealth()
    {
        return health;
    }
    void print()
    {
        cout<<"calling the print function with health "<<health<<endl;
    }
    hero(){
        cout<<"constructor called"<<endl;
    }
    hero(int health)
    {
        cout<<"this-> "<<this<<endl;
        this->health=health;
    }
    hero(int health,char level)
    {
        this->health=health;
        this->level=level;
    }
    
};
int main()
{
    hero ramesh(10);
    cout<<"Address of ramesh is "<<&ramesh<<endl;
    ramesh.gethealth();
    ramesh.print();

    //after creating this the default parameter's constructor dies itself
    //hence we cannot now create this 
    /*
    hero honda; //this will give error now
    */
    hero *pinki = new hero(88);
    pinki->print();

    //after creating this the default parameter's constructor dies itself

    hero temp(99,'9');


    //after creating this the default parameter's constructor dies itself

    temp.print();
    return 0;
}