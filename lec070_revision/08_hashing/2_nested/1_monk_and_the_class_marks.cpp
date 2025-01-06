/*
3 
eve 78
bob 99
alice 78

first based on marks descending order
if marks is same then lexiographical increasing order

bob 99
alice 78
eve 78

constraints
1<=n<=10^5
1<= |length of the name|<=100
1<=Marks<=100
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	map<int,multiset<string>>marks_map;
	while(q--){
		string st_names;
		int st_marks;
		cin>>st_names>>st_marks;
		marks_map[(-1*st_marks)].insert(st_names);
	}
	for(auto it: marks_map){
		auto &st = it.second;
		int marks = it.first;

		for(auto naming: st){
			cout<<naming<<" "<<(-1*marks)<<endl;
		}
	}

}
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin>>q;
    map<int,multiset<string>>mp;
    for(int i = 0;i<q;i++){
        string naming;
        int marks;
        cin>>naming>>marks;
        mp[marks].insert(naming);
    }
    map<int,set<string>>::iterator curr_it;
    curr_it = --mp.end();
    while(true){
        set<string> &st_iterator = (*curr_it).second;
        int marks = (*curr_it).first;
        for(auto student : st_iterator){
            cout<<student<<" "<<marks<<endl;
        }
        if(curr_it==mp.begin()) break;
        curr_it--;
    }
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	map<int,multiset<string>>mp;
	for(int i = 0;i<q;i++){
		string naming;
		int marks;
		cin>>naming>>marks;
		mp[marks].insert(naming);
	}
	map<int,multiset<string>> ::iterator it;
	it = mp.end();
	--it;
	while(true){
		multiset<string> st = (*it).second;
		int marking = (*it).first;
		for(string names: st){
			cout<<names<<" "<<marking<<endl;
		}
		if(it==mp.begin()) break;
		it--;
	}
	return 0;
}
*/
