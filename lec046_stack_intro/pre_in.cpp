#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix expression to infix expression
string prefixToInfix(const string& prefix) {
    stack<string> operandStack;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string operand1 = operandStack.top();
            operandStack.pop();
            string operand2 = operandStack.top();
            operandStack.pop();

            string infixExpression = "(" + operand1 + prefix[i] + operand2 + ")";
            operandStack.push(infixExpression);
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

    string infixExpression = prefixToInfix(prefixExpression);
    cout << "Infix expression: " << infixExpression << endl;

    return 0;
}
