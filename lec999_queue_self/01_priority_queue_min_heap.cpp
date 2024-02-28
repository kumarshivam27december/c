#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{

    //priority_queue<int> pq; //for maximum heap

    //min heap by default
    
    priority_queue<int , vector<int>,greater<int>> pq; 

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}
