#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>ans;
    for(int i = 2;i*i<=n;i++){
       
        while(n%i==0){
            ans.push_back(i);
            n= n/i;
            
        }
    }

    if(n>1){
        ans.push_back(n);
    }

    for(auto i:ans){
        cout<<i<<" ";
    }
}