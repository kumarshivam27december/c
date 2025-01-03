#include <bits/stdc++.h>
using namespace std;
int length_longest(string &str){
    unordered_set<char> st;
    int l = 0;
    int longest = 0;
    for(int r = 0;r<str.size();r++){
        while(st.find(str[r]) != st.end()){
            st.erase(str[l]);
            l++;
        }
        longest = max(longest,r-l+1);
        st.insert(str[r]);
    }
    return longest;
}
int main() {
    string str = "abcabcbb";
    int ans = length_longest(str);
    cout<<ans<<endl;
    return 0;
}