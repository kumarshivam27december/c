#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string convertPrefixToPostfix(string prefix) {
    stack<string> operandStack;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string operand1 = operandStack.top();
            operandStack.pop();
            string operand2 = operandStack.top();
            operandStack.pop();

            string newExpression = operand1 + operand2 + prefix[i];
            operandStack.push(newExpression);
        } else {
            operandStack.push(string(1, prefix[i]));
        }
    }

    return operandStack.top();
}

int main() {
    string prefixExpression;
    cout << "Enter a prefix expression: ";
    cin >> prefixExpression;

    string postfixExpression = convertPrefixToPostfix(prefixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
