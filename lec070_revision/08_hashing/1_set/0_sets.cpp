#include <bits/stdc++.h>
using namespace std;
void printset(set<string>&st){
    set<string> :: iterator it;
    for(it = st.begin();it!=st.end();++it){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    for(string value: st){
        cout<<value<<" ";
    }
}
int main() {
    set<string>st;
    st.insert("abc");
    st.insert("def");
    st.insert("ghij");
    set<string>::iterator it;
    it = st.find("abc");
    if(it!=st.end()){
        cout<<"Element " <<(*it)<<" was found";
        
    }else{
        cout<<"Element was not found";
    }

    st.erase("abc");
    set<string> ::iterator itt = st.begin();
    if(itt!=st.end()){
        st.erase(itt);
    }

    
    return 0;
}
/*

SET(ordered set)

it is somewhat similar to map data structure 
the only difference is it can hold only key instead of key and value
it is also made using red black tree
it have logn complexity of insertion
it has logn complexity for finding and erasing
it can hold multiple data structure like set inside vector pairs which cannot be beholded by unordered set

Unordered_set

same as unordered map 
it is also beholded like hash function
so compact data structure like 
pair vector set inside it cannot be used
we have to make it custom


if we need not need to be in sorted 
then we can use it 
time complexity of insertion 0(1)
time complexity of finding 0(1)



multiset
it also have similar property
to set

log n for insertion
log n for finding
it also can hold dublicate element

*/