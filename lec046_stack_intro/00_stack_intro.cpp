#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack <int> s;
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(12);
    s.push(11);
    s.push(10);
    s.push(1);
    s.pop();


    
    cout<<"the top element of the stack is "<<s.top()<<endl;
    if (s.empty())
    {
        cout<<"stack is empty"<<endl;
    }else{
        cout<<"the stack is not empty"<<endl;
    }
    
    return 0;
}