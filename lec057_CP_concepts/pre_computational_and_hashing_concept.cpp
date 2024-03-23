
//complexity O(N)+O(query*m) = O(m^2)
/*
//non optimize code
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int query;
    cin>>query;
    while(query--){
        int m ;
        cin>>m;
        int cnt = 0;
        for(int i =0;i<n;i++){
            if(m==arr[i]){
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}


*/

//optimize code 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e+7;
int hashArr[N];
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
        hashArr[a[i]]++;
    }

    int query;
    cin>>query;
    while(query--){
        int testcase;
        cin>>testcase;
        cout<<hashArr[testcase]<<endl;
    }
}
