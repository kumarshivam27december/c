#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string convertPostfixToPrefix(string postfix) {
    stack<string> operandStack;

    for (int i = 0; i < postfix.length(); i++) {
        if (isOperator(postfix[i])) {
            string operand2 = operandStack.top();
            operandStack.pop();
            string operand1 = operandStack.top();
            operandStack.pop();

            string newExpression = postfix[i] + operand1 + operand2;
            operandStack.push(newExpression);
        } else {
            operandStack.push(string(1, postfix[i]));
        }
    }

    return operandStack.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    string prefixExpression = convertPostfixToPrefix(postfixExpression);
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
