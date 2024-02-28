#include <iostream>
#include <stack>
int main() {
    stack<int> myStack;
    while (true) {
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                int value;
                cin >> value;
                myStack.push(value);
                break;
            case 2:
                if (!myStack.empty()) {
                    cout << "Popped element: " << myStack.top() << endl;
                    myStack.pop();
                } else {
                    cout << "Stack is empty. Cannot pop." << endl;
                }
                break;
            case 3:
                while (!myStack.empty()) {
                   cout << myStack.top() << " ";
                    myStack.pop();
                }
            cout << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    }

    return 0;
}