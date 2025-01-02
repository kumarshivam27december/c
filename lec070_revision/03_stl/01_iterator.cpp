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
    return 0;
}