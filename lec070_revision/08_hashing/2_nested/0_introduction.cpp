#include <bits/stdc++.h>
using namespace std;
void printnested(map<pair<string,string>,vector<int>>&mp){
    map<pair<string,string>, vector<int>> ::iterator it;
    for(it= mp.begin();it!=mp.end();++it){
        pair<string,string>key = it->first;
        vector<int>list = it->second;
        cout<<key.first<<" "<<key.second<<endl;
        cout<<"values"<<endl;
        for(auto i: list){
            cout<<i<<" ";
        }cout<<endl;
    } 
}
int main() {
    map<pair<int,int>,int> mp;
    pair<int,int> p1,p2;
    p1 = {1,2};p2 = {2,3};
    cout<<(p1<p2)<<endl;
    map<set<int>,int>mps;
    set<int>s1,s2;
    s1 = {2,3,4,5};s2 = {4,6,7,8};
    cout<<(s1<s2)<<endl;
    map<pair<string,string>,vector<int>>students;
    int n;cin>>n;
    for(int i = 0;i<n;i++){
        string first_name,last_name;
        int subjects_marks;
        cin>>first_name>>last_name>>subjects_marks;
        for(int j = 0;j<subjects_marks;j++){
            int individuals_marks;
            cin>>individuals_marks;
            students[{first_name,last_name}].push_back(individuals_marks);
        }
    }
    printnested(students);
    return 0;
}