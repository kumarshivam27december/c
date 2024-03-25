#include <bits/stdc++.h>
using namespace std;
string minWindow(string s,string t){
      if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> map(128, 0);
        int count = t.length();
        int left = 0, right = 0, minLen = INT_MAX, startIndex = 0;
        
        for (char c : t) {    //ADOBECODEBANC
            map[c]++;          //ABC
        }

        while (right < s.length()) {
            if (map[s[right++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                if (right - left < minLen) {
                    startIndex = left;
                    minLen = right - left;
                }

                if (map[s[left++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}
int main(){
    string a = "ADOBECODEBANC";
    string b = "ABC";
    cout<<minWindow(a,b)<<endl;
    return 0;
}