#include <bits/stdc++.h>
using namespace std;
int solve_min(vector<int>&arr,int size,int end){
    if(end==0){
        return 0;
    }
    return min(arr[end],solve_min(arr,size,end-1));
}
int solve_max(vector<int>&arr,int size,int end){
    if(end==0){
        return 0;
    }
    return max(arr[end],solve_max(arr,size,end-1));
}
int find_min(vector<int>&arr){
    return solve_min(arr,arr.size(),arr.size()-1);
}
int find_max(vector<int>&arr){
    return solve_max(arr,arr.size(),arr.size()-1);
}
int main(){
    vector<int>arr={3,4,-5,0,9,1,-8,78,0};
    cout<<find_min(arr);cout<<"\n";
    cout<<find_max(arr);
}