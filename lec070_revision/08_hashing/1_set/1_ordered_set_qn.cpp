/*
given n strings, print unique strings in 
lexiographical order
N<= 10^5
|S| <= 100000
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    set<string>st;
    while (n--)
    {
        string str;
        cin>>str;
        st.insert(str);
    }
    for(auto i : st){
        cout<<i<<endl;
    }
    for(string value : st){
        cout<<value<<endl;
    }
    for(set<string>::iterator it = st.begin();it!=st.end();++it){
        cout<<(*it)<<endl;
    }    
    return 0;
}