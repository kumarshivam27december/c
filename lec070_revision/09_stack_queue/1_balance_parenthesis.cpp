/*
STDIN           Function
-----           --------
3               n = 3
{[()]}          first s = '{[()]}'
{[(])}          second s = '{[(])}'
{{[[(())]]}}    third s ='{{[[(())]]}}'


yes
no
yes
*/
#include <bits/stdc++.h>
using namespace std;
bool isvalid(string str){
    stack<char>stk;
    for(int i = 0;i<str.size();i++){
        char ch = str[i];
        if(ch=='(' or ch=='{' or ch=='['){
            stk.push(ch);
        }else{
            if(stk.empty()){
                return false;
            }
            else if((ch==')' && stk.top()=='(') or (ch=='}' && stk.top()=='{') or (ch==']' && stk.top()=='[')){
                stk.pop();
            }else{
                return false;
            }
        }
    }
    return stk.empty();

}
int main() {
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        if(isvalid(str)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    
    }
    return 0;
}


/*
6
}][}}(}][))]
[](){()}
()
({}([][]))[]()
{)[](}]}]}))}(())(
([[)


NO
YES
YES
YES
NO
NO
*/