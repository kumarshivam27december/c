#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int l,int r,int mid){
    int l_size = mid-l+1;
    int r_size = r-mid;
    int left_arr[l_size+1];
    int right_arr[l_size+1];
    for(int i = 0;i<l_size;i++){
        left_arr[i]=arr[i+l];
    }
    for(int i = 0;i<r_size;i++){
        right_arr[i]= arr[i+mid+1];
    }
    left_arr[l_size] = right_arr[r_size] = INT_MAX;
    int left_pointer = 0;
    int right_pointer = 0;
    for(int i = l;i<=r;i++){
        if(left_arr[left_pointer] < right_arr[right_pointer]){
            arr[i] = left_arr[left_pointer];
            left_pointer++;
        }else{
            arr[i] = right_arr[right_pointer];
            right_pointer++;
        }
    }
}
void mergesort(vector<int>&arr,int l,int r){
    if(l==r){
        return;
    }
    int mid = (l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,r,mid);
}
int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}