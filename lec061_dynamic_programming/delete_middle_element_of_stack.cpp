#include <bits/stdc++.h>
#include <time.h>
using namespace std;
stack<int> del(stack<int> &stk)
{
    int size = stk.size();
    stack<int> rahul;
    int k = size / 2;
    while (k--)
    {
        int temp = stk.top();
        stk.pop();
        rahul.push(temp);
    }
    stk.pop();

    while(!rahul.empty()){
        int temp = rahul.top();
        rahul.pop();
        stk.push(temp);
    }
    return stk;
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
    stk.push(6);

    stack<int> ans = del(stk);
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000000));
    cout << endl;
    return 0;
}