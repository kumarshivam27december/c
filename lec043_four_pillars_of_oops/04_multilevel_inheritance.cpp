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
class bulldog: public dog{

};
int main()
{
    bulldog harsh;
    harsh.speaking();
    return 0;
}