#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main()
{
    string str = "fatman";
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char ch = str[i];

        s.push(ch);
    }
    cout<<endl;
    string ans = "";
    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();

    }

    cout<<"answer is "<<ans<<endl;
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    reverse(str.begin(),str.end());
    cout<<str;
    return 0;
}