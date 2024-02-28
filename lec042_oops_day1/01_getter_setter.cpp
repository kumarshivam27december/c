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
        health = h;//we can apply condition also so that if the password is correct then only one can change or set the value
        /*
        if(password==1234)
        {
            health = h;
        }
        password is passed as parameter here.
        */
    }
    void setlevel(char ch)
    {
        level = ch;
    }


};
int main()
{
    hero ramesh;
    cout<<"health of ramesh is "<<ramesh.gethealth()<<endl;
    ramesh.sethealth(70);
    cout<<"Health of ramesh after setting is "<<ramesh.gethealth()<<endl;
    return 0;
}