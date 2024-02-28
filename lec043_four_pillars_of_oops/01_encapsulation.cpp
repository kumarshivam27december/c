/*
what is encapsulation ?
wrapping up of data members and functions{inside a capsule  ->capsule is nothing but class}.
data members->property/state  && function->methods/behaviour
[INFORMATION HIDING AND DATA HIDING is known as encapsulation]

Fully encapsulation:
all data members is private  //// that is only same class can access it

advantage:-
1.data hide
2.class can be marked or made as read only
3.code reusability
4.unit testing



*/
#include <iostream>
using namespace std;
class hero{
    private:
      string name;
      int age;
      float height;
    public:
     int getage()
     {
        return this->age;
     }
};
int main()
{
    hero first;
    cout<<"All the best";
    return 0;
}