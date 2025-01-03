#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>arr = {3,2,1,4};
    vector<int>:: iterator it = arr.begin();
    for(it;it!=arr.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    vector<pair<int,int>>p_array = {{1,2},{2,3},{3,4}};
    vector<pair<int,int>>:: iterator itt;
    for(itt = p_array.begin();itt!=p_array.end();itt++){
        cout<<(*itt).first<<" "<<(*itt).second<<endl;
    }
    for(itt = p_array.begin();itt!=p_array.end();itt++){
        cout<<itt->first<<" "<<itt->second<<endl;
    }
    //vallue based iterators
    vector<pair<int,int>> vp = {{1,2},{2,3},make_pair(3,4)};
    for(pair<int,int> &p: vp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    //auto keyword dynamically determine the data type of something
    auto a = 1;
    auto b = "shivam";
    vector<pair<int,int>>::iterator ittt;
    for(ittt = vp.begin();ittt!=vp.end();ittt++){
        cout<<(*ittt).first<<" "<<(*ittt).second<<endl;
    } //so instead of above for loop we can use more easier way to traverse that is using dynamiccaly determining the data type of iterators using auto keyword
    for(auto i : vp){
        cout<<i.first<<" "<<i.second<<endl;
    }//or we can also use 
    for(auto itttt = vp.begin();itttt!=vp.end();itttt++){
        cout<<(*itttt).first<<" "<<(*itttt).second<<endl;
    }// or we can also use
    for(auto itttt = vp.begin();itttt!=vp.end();itttt++){
        cout<< itttt->first<<" "<<itttt->second<<endl;
    }
}