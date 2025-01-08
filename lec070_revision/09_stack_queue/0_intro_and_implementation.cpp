#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<long long>stk;
    stk.push(7);
    stk.push(77);
    stk.push(777);
    stk.push(7777);
    stk.push(77777);
    stk.push(777777);
    stk.push(7777777);
    cout<<"Stack elements are"<<endl;
    while(!stk.empty()){
        cout<<stk.top()<<"\n";
        stk.pop();
    }
    cout<<endl;
    cout<<"Queue elements are"<<endl;
    queue<string>q;
    q.push("s");
    q.push("sh");
    q.push("shi");
    q.push("shiv");
    q.push("shiva");
    q.push("shivam");   


    while(!q.empty()){
        cout<<q.front()<<"\n";
        q.pop();
    }



    return 0;
}