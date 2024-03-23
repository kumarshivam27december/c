#include <bits/stdc++.h>
using namespace std;
int secondlargest(vector<int> &v){
    
    //method 1
    int ans = INT_MIN;
    sort(v.begin(),v.end());
    for(int i = v.size()-1;i>1;i--){
        if(v[i]!=v[i-1]){
            ans = v[i-1];
            break;
        }
    }
    return ans;


}
int main(){
    vector<int> v = {1,2,4,7,7,9,9,9,9,9,9,8};
    cout<<secondlargest(v)<<endl;
    return 0;
}