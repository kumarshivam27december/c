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

/*
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int ans = 0;
        int char_count[128] = {0};
        for (int l = 0, r = 0; r < n; r++)
        {
            char_count[s[r]]++;
            while (char_count[s[r]] > 1)
            {
                char_count[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
*/

int main()
{
    string s = "abcabcaabb";
    cout << lengthOfLongestSubstring(s) << "\n";
    return 0;
}