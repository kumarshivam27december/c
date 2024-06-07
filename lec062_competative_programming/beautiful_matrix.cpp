#include <bits/stdc++.h>
using namespace std;
int main(){
int arr[5][5];
for(int i=0;i<5;i++){
	for(int j = 0;j<5;j++){
		cin>>arr[i][j];
	}
}

vector<int>ans;
for(int i =0;i<5;i++){
	for(int j = 0;j<5;j++){
		if(arr[i][j]==1){
			ans.push_back(i);
			ans.push_back(j);
		}
	}
}

int a = abs(ans[0]-2);
int b = abs(ans[1]-2);
cout<<a+b;
return 0;
}
