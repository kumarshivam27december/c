#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto x:strs){
            string temp = x;
            sort(x.begin(),x.end());
            mp[x].push_back(temp);
        }
        for(auto x:mp){
            vector<string> temp = x.second;
            ans.push_back(temp);
        }
        return ans;
    }
};
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution sol;
    vector<vector<string>> anagrams = sol.groupAnagrams(strs);

    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : anagrams) {
        cout << "[";
        bool first = true;
        for (const auto& word : group) {
            if (!first) {
                cout << ", ";
            }
            cout << word;
            first = false;
        }
        cout << "]" << endl;
    }

    return 0;
}


