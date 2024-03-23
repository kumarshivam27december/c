#include <iostream>
#include <stack>
using namespace std;

stack<int> deleteMiddleElement(stack<int> s, int size) {
    // If stack is empty or has only one element, return the stack as it is
    if (s.empty() || size == 1) {
        return s;
    }

    // Find the middle index of the stack
    int mid = size / 2;

    // Temporary stack to hold elements before the middle element
    stack<int> tempStack;

    // Remove and store elements before the middle element in the temporary stack
    for (int i = 0; i < mid; i++) {
        tempStack.push(s.top());
        s.pop();
    }

    // Remove the middle element
    s.pop();

    // Restore elements from the temporary stack back to the original stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }

    return s;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);


    int size = s.size();

    // Delete the middle element from the stack
    s = deleteMiddleElement(s, size);

    // Print the stack after deleting the middle element
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
