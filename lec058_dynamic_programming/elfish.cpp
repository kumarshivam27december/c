/* [Medium hard] A word is considered elfish if it contains the
letters: e, l, and f in it, in any order. For example, we would say
that the following words are elfish: whiteleaf, tasteful, unfriendly,
and waffles, because they each contain those letters.
• Write a predicate function called elfish? that, given a word,
tells us if that word is elfish or not.
• Write a more generalized predicate function called x-ish? that,
given two words, returns true if all the letters of the first word
are contained in the second.*/

#include <bits/stdc++.h>
using namespace std;
bool recursion(string &str,int i,int cnt_e,int cnt_l,int cnt_f){
	if(cnt_e>0 && cnt_l>0 && cnt_f>0){
		return true;
	}
	
	if(i>=str.size()){
		return false;
	}
	if(str[i]=='e'){
		return recursion(str,i+1,cnt_e+1,cnt_l,cnt_f);
	}
	if(str[i]=='l'){
		return recursion(str,i+1,cnt_e,cnt_l+1,cnt_f);
	}
	if(str[i]=='f'){
		return recursion(str,i+1,cnt_e,cnt_l,cnt_f+1);
	}
	
	return recursion(str,i+1,cnt_e,cnt_l,cnt_f);

}
int main(){
	string str;
	cin>>str;
	int cnt_e=0;int cnt_l=0;int cnt_f = 0;
	if(recursion(str,0,cnt_e,cnt_l,cnt_f)){
		cout<<"The string is elfish";
	}else{
		cout<<"The string is not elfish";
	}
	return 0;
}
