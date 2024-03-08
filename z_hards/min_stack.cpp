#include <bits/stdc++.h>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;

    MinStack() {}

    void push(int val) {
        stk.push(val);
        if (min_stk.empty() || val <= min_stk.top()) {
            min_stk.push(val);
        }
    }

    void pop() {
        if (stk.top() == min_stk.top()) {
            min_stk.pop();
        }
        stk.pop();
    }

    int top() {
        if (stk.empty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1; // Or throw an exception
        }
        return stk.top();
    }

    int getMin() {
        if (min_stk.empty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1; // Or throw an exception
        }
        return min_stk.top();
    }
};

int main() {
    MinStack minStack;

    // Test Case 1: Basic Functionality
    minStack.push(3);
    minStack.push(1);
    minStack.push(2);
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 1
    minStack.pop();
    cout << "Minimum element after pop: " << minStack.getMin() << endl; // Output: 1 or 2

    // Test Case 2: Empty Stack Handling
    cout << "\nTesting empty stack:\n";
    minStack.pop(); // Should handle pop on empty stack
    minStack.pop(); // Should handle pop on empty stack
    cout << "Minimum element (empty stack): " << minStack.getMin() << endl; // Should print error message or default value

    // Test Case 3: Repeated Minimum Value
    cout << "\nTesting repeated minimum:\n";
    minStack.push(5);
    minStack.push(5);
    minStack.push(2);
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 2
    minStack.pop();
    cout << "Minimum element after pop: " << minStack.getMin() << endl; // Output: 2

    return 0;
}
