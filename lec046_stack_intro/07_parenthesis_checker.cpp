#include <iostream>
#include <stack>
using namespace std;
bool isparenthesis(string expr){
    stack<char> s;
    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];
        if (ch=='(' || ch== '{' || ch=='[')
        {
            s.push(ch);
        }
        else{
            
            if (!s.empty()){
                char top = s.top();
                if ((ch==')' && top == '(') ||
                    (ch=='}' && top == '{') ||
                    (ch==']' && top == '[') ){
                    
                    s.pop();
                }else{
                    return false;
                }    
            }
            else{
                return false;
            }
            
        }


        
    }
    
        if (s.empty())
        {
            return true;
        }else{
            return false;
        }
        

}
int main()
{
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (isparenthesis(expression))
        cout << "The expression has balanced parentheses." << endl;
    else
        cout << "The expression has unbalanced parentheses." << endl;

    return 0;
}
