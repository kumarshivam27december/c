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

// Function to convert infix expression to prefix expression
std::string infixToPrefix(const std::string& infix) {
    std::stringstream prefix;
    std::stack<char> operatorStack;

    for (int i = infix.size() - 1; i >= 0; i--) {
        char c = infix[i];

        // If the character is an operand, add it to the prefix expression
        if (isalnum(c)) {
            prefix << c;
        }
        // If the character is a closing parenthesis, push it to the stack
        else if (c == ')') {
            operatorStack.push(c);
        }
        // If the character is an open parenthesis, pop all operators from the stack until a closing parenthesis is encountered
 else if (c == '(') {
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefix << operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop the closing parenthesis
        }
        // If the character is an operator, pop higher or equal precedence operators from the stack to the prefix expression
        // and then push the current operator to the stack
        else if (isOperator(c)) {
            while (!operatorStack.empty() && operatorStack.top() != ')' && getPrecedence(c) < getPrecedence(operatorStack.top())) {
                prefix << operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Pop any remaining operators from the stack to the prefix expression
    while (!operatorStack.empty()) {
        prefix << operatorStack.top();
        operatorStack.pop();
    }

    // Reverse the prefix expression to get the final result
    std::string result = prefix.str();
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    std::string prefixExpression = infixToPrefix(infixExpression);
    std::cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
