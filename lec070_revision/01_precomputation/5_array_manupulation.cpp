/*
Function Description

Complete the function arrayManipulation in the editor below.

arrayManipulation has the following parameters:

int n - the number of elements in the array
int queries[q][3] - a two dimensional array of queries where each queries[i] contains three integers, a, b, and k.
Returns

int - the maximum value in the resultant array


    n = 10
    q = 3
    a b k
    1 5 3
    4 8 7
    6 9 1

index->	 1 2 3  4  5 6 7 8 9 10
        [0,0,0, 0, 0,0,0,0,0, 0]
        [3,3,3, 3, 3,0,0,0,0, 0]
        [3,3,3,10,10,7,7,7,0, 0]
        [3,3,3,10,10,8,8,8,1, 0]
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<int>arr(N);
int main() {
    int n,m;
    cin>>n>>m;
    while(m--){
        int l,r,num;
        cin>>l>>r>>num;
        arr[l]+=num;
        arr[r+1]-=num;
    }

    for(int i = 1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
    int maxi = *max_element(arr.begin(),arr.end());
    cout<<maxi<<endl;
    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<int>arr(N);
int main() {
    int n,m;
    cin>>n>>m;
    while(m--){
        int l,r,num;
        cin>>l>>r>>num;
        for(int i = l;i<=r;i++){
            arr[i]+=num;
        }
    }
    int maxi = *max_element(arr.begin(),arr.end());
    cout<<maxi<<endl;
    return 0;
}
*/

