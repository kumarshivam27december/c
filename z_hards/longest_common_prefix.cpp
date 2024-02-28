#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0) return "";
    string ans = "";
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size()-1];
    for(int i = 0;i<first.size();i++){
        if(first[i]!=last[i]){
            break;
        }
        ans.push_back(first[i]);
    }
    return ans;
}
int main(){
    vector<string> str= {"abc","abcd,abcdefg","abcdh","abcdek"};
    cout<<longestCommonPrefix(str)<<endl;
}