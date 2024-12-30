/*
given array a  of n integer 
given q queries and in each queru
given l and r print sum of array 
element from index l to r (l,r) included
constraints
1 to n to 10^5
1 to a[i] to 10^9
1 to q to 10^5
1<=L,R<=N
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int prefix[N];
int main() {
    int n;
    cin>>n;
    vector<int>arr;
    int k = n;
    while(k--){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    prefix[0]=arr[0];
    for(int i = 1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;

        if(l==0){
            cout<<prefix[r]<<endl;
        }else{
        cout<<prefix[r]-prefix[l-1]<<endl;
        }
    }
    return 0;
}
