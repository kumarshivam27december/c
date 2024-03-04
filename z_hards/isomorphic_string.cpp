#include <bits/stdc++.h>
using namespace std;
bool isisomorphic(string str1,string str2){
    int n = str1.length();
    unordered_map<char,char> mp1;
    unordered_map<char,bool> flag;
    for(int i = 0;i<str1.size();i++){
        if(mp1.count(str1[i])){
            if(mp1[str1[i]]!=str2[i]){
                return false;
            }
        }else{
            if(flag[str2[i]]){
                return false;
            }
            mp1[str1[i]] = str2[i];
            flag[str2[i]] = true;
        }
    }
    return true;
}
int main(){
    string str1 = "foo";
    string str2 = "add";
    if(isisomorphic(str1,str2)){
        cout<<"Strings are isomorphic"<<endl;
    }else{

        cout<<"Strings are not isomorphic"<<endl;
    }
    return 0;
}



