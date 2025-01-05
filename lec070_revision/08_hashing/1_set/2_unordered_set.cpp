/*
same as unordered map 
if we need not need to be in sorted 
then we can use it 
time complexity of insertion 0(1)
time complexity of finding 0(1)
*/
/*
Question:
given n string and q queries.
in each query you are given a string
print yes if string is present else print no
N<=10^6
|s|<=100
Q<=10^6

*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    unordered_set<string>st;
    while(n--){
        string str;
        cin>>str;
        st.insert(str);
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;

        unordered_set<string>::iterator itt;
        itt = st.find(str);
        if(itt!=st.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}

