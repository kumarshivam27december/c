#include <iostream>
#include <cstring>
using namespace std;
class Hero{
    //attributes
    public:
    int health;
    char name[10];
    char level;
    void print(){
        cout<<"level is :"<<level<<endl;
    }
};
int main()
{
    Hero shivam;

    //setting the values 
    shivam.health=100;
    ////shivam.name="shiv";
    strcpy(shivam.name, "shivam");
    shivam.level='A';
    cout<<"Health of shivam is :"<<shivam.health<<endl;
    cout<<"Name of shivam is : "<<shivam.name<<endl;
    cout<<"level of shivam is : "<<shivam.level<<endl;
    return 0;
}