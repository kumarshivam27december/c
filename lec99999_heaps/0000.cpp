#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int k = a;
    vector <char> v;
    while(a){
        char ch;
        cin>>ch;
        v.push_back(ch);
        a--;
    }


    int pos;cin>>pos;
    char key;cin>>key;

    if(pos>k){
        cout<<"Invalid ";
        return 0;
    }

    v.insert(v.begin()+pos,key);

    for(auto it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }

    return 0;
}


/*


4 
a b c d
2 
e


a b e c d

if baahar-> invalid


*/