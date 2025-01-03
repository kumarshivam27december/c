#include <bits/stdc++.h>
using namespace std;
int removedublicate(vector<int>&arr){
    int i = 1;
    for (int j = 1; j < arr.size(); j++){
        if(arr[j]!=arr[j-1]){
            arr[i] = arr[j];
            i++;
        }
    }
    return i;
}
int main() {
    vector<int>arr = {0,0,1,1,1,2,2,3,3,4};
    int solve = removedublicate(arr);
    for(int i = 0;i<solve;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}