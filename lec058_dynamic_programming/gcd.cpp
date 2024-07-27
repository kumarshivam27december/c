#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b){
	if(a==1){
		return b;
	}
	if(b==1){
		return a;
	}

	return GCD(b%a,b);
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<GCD(a,b)<<endl;
	return 0;
}
