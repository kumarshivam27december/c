/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i = 0;i<n;i++){
        int minindex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]< arr[minindex]){
                minindex=j;
            }
        }        
        swap(arr[i],arr[minindex]);
    }



    for(auto i: arr){
        cout<<i<<" ";
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int>&arr,int n,int idx){
    if(idx==n-1){
        return;
    }

    int curr_min = idx;
    for(int i = idx+1;i<n;i++){
        if(arr[i]<arr[curr_min]){
            curr_min = i;
        }
    }
    swap(arr[idx],arr[curr_min]);
    selection_sort(arr,n,idx+1);
}
int main() {
    int p;
    cin>>p;
    vector<int>arr(p);
    for(int i = 0;i<p;i++){
        cin>>arr[i];
    }
    selection_sort(arr,p,0);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}