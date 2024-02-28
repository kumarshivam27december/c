#include <iostream>
using namespace std;
class animal{
    public:
    int  age;
    int weight;
    public:
    void barking()
    {
        cout<<"barking"<<endl;
    }
};
class dog: public animal{

};
class human{
    public:
    string color;
    public:
    void speaking()
    {
        cout<<"speaking"<<endl;
    }
};
class hybrid:public animal,public human{

};
int main()
{
    hybrid h1;
    h1.speaking();
    h1.barking();
    return 0;
}