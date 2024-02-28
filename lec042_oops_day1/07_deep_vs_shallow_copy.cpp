#include <iostream>
#include<cstring>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;
    char *name;
    hero()
    {
        cout<<"default constructor called \n"<<endl;
        name = new char[100];
    }

    int gethealth()
    {
        return health;
    }
    void sethealth(int h)
    {
        health = h;
    }

    void setlevel(char ch)
    {
        level = ch;
    }

    char getlevel()
    {
        return level;
    }
    void setname(char name[])
    {
        strcpy(this->name,name);
    }
    void print()
    {
        cout<<endl;
        cout<<"[ name is: "<<this->name<<" ,";
        cout<<"Health is: "<<this->health<<" ,";
        cout<<"level is: "<<this->level<<" ]";
        cout<<endl;
        cout<<endl;
    }
    hero(hero& temp)
    {
        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        cout<<"manual copy constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }


};
int main()
{

    /* default copy constructor is shallow copy
    as it just copy the same pointer
    it does not create to refer it so any change in parent 
    will affect its child
    */
    hero h1;
    h1.sethealth(70);
    h1.setlevel('D');
    char name[7]="Babbar";
    h1.setname(name); 
    h1.print();

    //copy
    hero h2=h1;// or we can do ////hero h2(h1);
    h2.print();

    h1.name[0]='G';
    h1.print();
    h2.print(); 
    return 0;
}