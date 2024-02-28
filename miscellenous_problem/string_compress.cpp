/*
test case 1:-
/lmn/abcd/..//b/./cd/ab//.//


/lmn/b/cd/ab

test case2:-

/../

/

test case 3:-

/./././.././././../

/

*/

#include <bits/stdc++.h>
#include <cstring>
using namespace std;
string compress(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '/')
        {
            s.push(str[i]);
            if (str[i+1] == '/')
            {
                i++;
            }
        
        }
        else if (str[i] == '.')
        {
            if (str[i + 1] == '.')
            {
                if(s.size()>=2){
                s.pop();
                while (s.top() != '/')
                {
                    s.pop();
                }
                s.pop();
                i++;
                }
                
                else if(s.size()>1){
                    s.pop();
                }
            }
            else
            {
                if(s.size()>1){
                s.pop();
                }
            }
        }
        else{
            s.push(str[i]);
        }
    }
    if(s.top()=='/'){
        s.pop();
    }
    string str1 = "";
    for(int i=s.size()-1;i>=0;i--){
        str1 += s.top();
        s.pop();
        
    }


    if(str1.empty()){
        str1+='/';
    }
    else{
    reverse(str1.begin(),str1.end());
    }
    return str1;
}
int main()
{
    string str = "/./././.././././../";
    string newstr = compress(str);
    cout << newstr << endl;
    return 0;
}