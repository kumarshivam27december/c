#include <bits/stdc++.h>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> stk; 
    stack<int> min_stk; 

    MinStack() {

    }

    void push(int val) {
        stk.push(val);
        if(min_stk.empty() || min_stk.top()>=val){
            min_stk.push(val);
        }
    }
    void pop(){
        if(stk.top()==min_stk.top()){
            min_stk.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(1);
    minStack.push(2);
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 1
    minStack.pop();
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 1 or 2 (depending on initial value in min_stk)
    return 0;
}
