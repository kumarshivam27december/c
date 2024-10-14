#include <bits/stdc++.h>
using namespace std;
vector<int> indexes(vector<int>&v,int target){
	vector<int>ans;
	unordered_map<int,int>mp;
	for(int i = 0;i<v.size();i++){
		int num = abs(target-v[i]);
		if(mp.find(num)!=mp.end()){
			ans.push_back(mp[num]);
			ans.push_back(i);
			break;
		}
		mp[v[i]] =  i;
	}
	return ans;
}
int main(){
vector<int> v= {2,7,9,11};
vector<int> ans =  indexes(v,9);
for(auto i : ans){
	cout<<i<<" ";
}
return 0;
}
