#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue <int> pqr;
    pqr.push(10);
    pqr.push(50);
    pqr.push(20);
    pqr.push(90);
    pqr.push(80);
    pqr.push(70);
    while(!pqr.empty()){
        cout<<pqr.top()<<" ";
        pqr.pop();
    }cout<<endl;
    priority_queue <int ,vector<int> , greater<int>> pq;
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(90);
    pq.push(80);
    pq.push(70);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

}