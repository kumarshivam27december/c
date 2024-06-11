#include <bits/stdc++.h>
using namespace std;
int main(){
	int num;
	cin>>num;
	bool consists = true;
	string str = to_string(num);
	for(int i =0;i<str.size();i++){
		if(str[i]!='4' && str[i]!='7'){
			consists=false;
			break;
		}
	}
	if(consists==false){
		if(num%4==0 ||num%7==0||num%47==0){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}else{
		cout<<"YES";
	}
	return 0;
}
