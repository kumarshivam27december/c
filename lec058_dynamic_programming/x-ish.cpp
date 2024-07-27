#include <bits/stdc++.h>
using namespace std;
bool ispresent(string &s1,string &s2,int i,int j){
    vector<bool>v(s1.size(),false);
    for(int i = 0;i<s1.size();i++){
    	char ch = s1[i];
	for(int j= 0;j<s2.size();j++){
		if(ch==s2[j]){
			v[i]=true;
		}
	}
    }

    for(int i = 0;i<v.size();i++){
    	if(v[i]==false){
		return false;
	}
    }
    return true;
}
int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    //check if all the elements of s1 is present in s2 or not
    if(ispresent(s1,s2,0,0)){
        cout<<"all the elements are present in string 2";
    }else{
        cout<<"all the elements are not present in string 1";
    }
}
