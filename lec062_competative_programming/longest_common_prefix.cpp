#include <bits/stdc++.h>
using namespace std;
string prefix(vector<string> &arr){
	sort(arr.begin(),arr.end());
	string start = arr[0];
	string ending = arr[arr.size()-1];
	int i = 0;
	int sizes = min(start.size(),ending.size());
	while(i<sizes && start[i]==ending[i]){
		i++;
	}
	string str =   start.substr(0,i);
	return str==""?"-1":str;
}
int main(){
	vector<string>str = {"geeksforgeeks","geefs","geeks","geekfor"};
	string ans = prefix(str);
	cout<<ans;
	return 0;
}
