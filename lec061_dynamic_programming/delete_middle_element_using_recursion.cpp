#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void helper(stack<int>&stk,int count,int pos){
    if(stk.empty()) return;

    if(count==pos) stk.pop();

    int temp = stk.top();
    stk.pop();

    helper(stk,count+1,pos);
    stk.push(temp);
}
void del(stack<int> &stk){
    int pos = ceil(stk.size()/2.0);
    helper(stk,1,pos);
}
int main()
{
    clock_t tStart = clock();
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    // stk.push(6);

    del(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout << endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000000));
    cout << endl;
    return 0;
}