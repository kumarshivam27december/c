 <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix expression to infix expression
string postfixToInfix(const string& postfix) {
    stack<string> operandStack;

    for (char c : postfix) {
        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            operandStack.push(string(1, c));
        }
        // If the character is an operator, pop two operands from the stack
        // and enclose them in parentheses with the operator in between, then push the result back to the stack
        else if (isOperator(c)) {
            string operand2 = operandStack.top();
            operandStack.pop();
            string operand1 = operandStack.top();
            operandStack.pop();

            string infixExpression = "(" + operand1 + c + operand2 + ")";
            operandStack.push(infixExpression);
        }
    }

    return operandStack.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    string infixExpression = postfixToInfix(postfixExpression);
    cout << "Infix expression: " << infixExpression << endl;

    return 0;
}
