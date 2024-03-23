#include <bits/stdc++.h>
using namespace std;
string simplify(string path){
    stack<string>stk;
    string ans ="";
    for(int i = 0;i<path.size();i++){
        if(path[i]=='/'){
            continue;
        }
        string temp;
        while(i<path.size() && path[i]!='/'){
            temp+=path[i];
            i++;
        }
        if(temp=="."){
            continue;
        }
        else if(temp==".."){
            if(!stk.empty()){
                stk.pop();
            }
        }
        else{
            stk.push(temp);
        }

    }
    while(!stk.empty()){
        ans = '/'+stk.top()+ans;
        stk.pop();
    }

    if(ans.size()==0){
        return "/";
    }
    return ans;
}
int main(){
    string path = "/home//foo/../abc//efg//.klm//..";
    cout<<simplify(path)<<endl;
    return 0;
}