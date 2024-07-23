/*
 *in this question we have to sort the array
 *in such way that the number whuch has least frequency comes first
 *if both has same frequency then the lexigraphy  greater element will come first
 *i.e the greater element will come first
 * */


#include <bits/stdc++.h>
using namespace std;
vector<int> freq_sort(vector<int>&arr){
	unordered_map<int,int>mp;
	for(auto x: arr){
		mp[x]++;
	}

	sort(arr.begin(),arr.end(),[&](int a,int b){
		return (mp[a]!=mp[b])?mp[a]<mp[b]:a>b;		
	});
	return arr;
}
int main(){
	vector<int>arr={1,1,2,2,2,3};
	vector<int> bns = freq_sort(arr);
	for(auto i:bns){
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
