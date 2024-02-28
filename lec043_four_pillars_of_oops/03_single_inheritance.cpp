#include <iostream>
using namespace std;
class animal{
    public:
    int  age;
    int weight;
    public:
    void speaking()
    {
        cout<<"speaking"<<endl;
    }
};
class dog: public animal{

};
int main()
{
    dog d1;
    cout<<d1.age<<endl;
    d1.speaking();
    return 0;
}