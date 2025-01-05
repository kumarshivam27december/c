/*
multiset
it also have similar property
to set
log n for insertion
log n for finding
it also can hold dublicate element
*/
#include <bits/stdc++.h>
using namespace std;
void printset(multiset<string>&mp){
    cout<<"The size of multiset is "<<mp.size()<<endl;
    multiset<string> ::iterator it;
    for(it = mp.begin();it!=mp.end();++it){
        cout<<(*it)<<endl;
    }
}
int main() {
    multiset<string>st;
    st.insert("abc");//O(log(n))
    st.insert("def");
    st.insert("ghi");
    st.insert("abc");
    printset(st);
    cout<<endl;
    //if we use iterator to delete item it only delete the element which was pointed toward the iterator but if we directly delete the key it will delete all the occurences of the key
    //while erasing using key it find all the iterator for that key till it is not present anymore and then delete it all
    multiset<string> ::iterator itt = st.find("abc");
    st.erase(itt);
    printset(st);
    st.insert("abc");
    printset(st);
    st.erase("abc");
    printset(st);
    return 0;
}