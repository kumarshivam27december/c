#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int maxlength = 0;
    int left = 0;
    unordered_map<char, int> mp;
    for (int right = 0; right < s.length(); right++)
    {
        char c = s[right];
        if (mp.find(c) != mp.end() && mp[c] >= left)
        {
            left = mp[c] + 1;
        }
        maxlength = max(maxlength, right - left + 1);
        mp[c] = right;
    }
    return maxlength;
}
int main(){
    string s = "abcabcaabb";
    cout<<lengthOfLongestSubstring(s)<<"\n";
    return 0;
}