#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&arr,int target){
    int l = 0;
    int r = arr.size()-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]>target){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7};
    int ans = binary_search(arr,5);
    cout<<"index is "<<ans<<endl;
    return 0;
}