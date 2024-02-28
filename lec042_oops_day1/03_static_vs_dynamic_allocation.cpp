#include <iostream>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;
    void print()
    {
        cout<<health<<endl;
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
};
int main()
{
    //statically allocation
    hero kamlesh;
    kamlesh.sethealth(69);
    kamlesh.level='c';
    cout<<"health od kamlesh is : "<<kamlesh.gethealth()<<endl;
    cout<<"level of kamlesh is : "<<kamlesh.level<<endl;

    //dynamically allocation
    hero *ramesh = new hero;
    ramesh->sethealth(6969);
    ramesh->setlevel('f');
    cout<<"Health of ramesh is : "<<(*ramesh).gethealth()<<endl;
    cout<<"level of ramesh is : "<<(*ramesh).level<<endl;
    //alter dynamically allocation dereferencing
    cout<<"Health of ramesh is : "<<ramesh->gethealth()<<endl;
    cout<<"level of ramesh is : "<<ramesh->level<<endl;

    return 0;
}