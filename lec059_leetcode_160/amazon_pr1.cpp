#include <bits/stdc++.h>
using namespace std;
int main(){
	string input;
	getline(cin,input);
	int length = input.length()+1;
	char arr[length];
	strcpy(arr,input.c_str());

	stack<int>stk;
	for(int i = 0;i<length;i++){
		if(arr[i]=='P'){
			stk.push(arr[i+2]);
		}
		else if(arr[i]=='B'){
			if(stk.top()==arr[i+2]){
				stk.pop();
			}else{
				cout<<i/4<<endl;
				return 0;
			}
		
		}
	}
	if(stk.empty()==true){
		cout<<-1<<endl;
	}
	/*//cout<<"-1"<<endl;*/
	return 0;

}
