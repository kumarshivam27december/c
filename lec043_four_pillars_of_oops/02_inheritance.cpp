/*
human - parent class
male female - child class


*/
#include <iostream>
using namespace std;
class human{
    public:
    int height;
    int weight;
    int age;
    public:
    int getage()
    {
        return this->age;
    }
    void setage(int a)
    {
        this->age=a;
    }
    void setweight(int w)
    {
        this->weight=w;
    }
};
class male: public human{
    public:
    string color;
    void sleeping()
    {
        cout<<"male is sleeping";
    }
};
int main()
{
    male obj1;
    cout<<obj1.age<<endl;
    cout<<obj1.height<<endl;
    cout<<obj1.weight<<endl;
    cout<<obj1.color<<endl;
    obj1.setweight(75);
    obj1.setage(10);
    cout<<obj1.age<<endl;
    cout<<obj1.weight<<endl;

    return 0;

}
/*
types of inheritence
1.simple
2.multilevel
3.multiple
4.hybrid
5.hierarichle


*/