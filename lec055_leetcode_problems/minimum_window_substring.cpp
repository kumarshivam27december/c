#include <bits/stdc++.h>
using namespace std;
string minWindow(string a,string b){
    if(b.size()>a.size() || b.size()==0 ||a.size()==0){
        return "";
    }
    vector<int> map(128,0);
    int count = 0;
    int left  = 0;
    int right = 0;
    int minlen = INT_MAX;
    int startindex = 0;


    for(char c:b){
        map[c]++;
    }

    while(right < a.size()){
        if(map[a[right++]]-- > 0){
            count--;
        }
        
    }
}
int main(){
    string a = "ADOBECODEBANC";
    string b = "ABC";
    cout<<minWindow(a,b)<<endl;
    return 0;
}