#include <iostream>
#include <stack>
#include <string>
#include <sstream>

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

 Function to convert infix expression to postfix expression
std::string infixToPostfix(const std::string& infix) {
    std::stringstream postfix;
    std::stack<char> operatorStack;

    for (char c infix) {
        // If the character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix << c;
        }
        // If the character is an open parenthesis, push it to the stack
        else if (c == '(') {
            operatorStack.push(c);
        }
        // If the character is a closing parenthesis, pop all operators from the stack until an open parenthesis is encountered
        else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix << operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop the open parenthesis
        }
        // If the character is an operator, pop higher or equal precedence operators from the stack to the postfix expression
        // and then push the current operator to the stack
        else if (isOperator(c)) {
            while (!operator.empty() && operatorStack.top() != '(' && getPrecedence(c) <= getPrecedence(operatorStack.top())) {
                postfix << operatorStack.top();
                operatorStack.pop            }
            operatorStack.push(c);
        }
    }

    // Pop any remaining operators from the stack to the postfix expression    while (!operatorStack.empty()) {
        postfix << operatorStack.top();
        operatorStack.pop();
    }

    return postfix.str();
}

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}
