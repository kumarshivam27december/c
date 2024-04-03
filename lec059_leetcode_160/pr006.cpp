/*

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


*/


#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void rotating(vector<int>&v,int k){
    int m = k%v.size();
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+(m));
    reverse(v.begin()+m,v.end());
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {1,2,3,4,5,6,7};
    int k = 3;
    rotating(v,k);
    cout<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}