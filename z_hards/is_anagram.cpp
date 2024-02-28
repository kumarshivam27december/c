#include <bits/stdc++.h>
using namespace std;
bool isanagram(string s,string t){
    if(s.size()!=t.size()) return false;

   
   /*
    int map[26] = {0};
    for(int i = 0;i<s.size();i++){
        map[s[i]-'a']++;
        map[t[i]-'a']--;
    }

    for(auto i:map){
        if(i !=0) return false;
    }
    return true;

    */

   map<char,int> mp;
   for(int i =0;i<s.size();i++){
    mp[s[i]]++;
    mp[t[i]]--;
   }

   for(auto x :mp ){
    if(x.second!=0) return  false;
   }
   return true;
}
int main(){
    string s = "anagram";
    string t = "graaamn";
    if(isanagram(s,t)){
        cout<<"It is anagram";
    }else{
        cout<<"It is not anagram";
    }
    return 0;
}


/*

#include <map>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    map<char, int> charCount;

    for (int i = 0; i < s.size(); i++) {
        charCount[s[i]]++;
        charCount[t[i]]--;
    }

    for (const auto& pair : charCount) {
        if (pair.second != 0) return false;
    }

    return true;
}


*/