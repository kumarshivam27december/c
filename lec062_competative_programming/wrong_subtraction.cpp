#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int a,b;
	cin>>a>>b;
	while(b--){
		if(a%10==0){
			a/=10;
		}else{
			a-=1;
		}
	}
	cout<<a;
}
