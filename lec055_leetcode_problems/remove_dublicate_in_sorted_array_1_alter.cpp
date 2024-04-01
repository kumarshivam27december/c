#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int remove_dublicate(vector<int> &nums){
    int j = 1;
    for(int i = 1 ;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            nums[j]=nums[i];
            j++;
        }
    }
    return j;
}
int main()
{
    clock_t tStart = clock();
    vector<int> nums = {0,0,1,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,4,4,5,5,5,6,7};
    int ans = remove_dublicate(nums);
    for(int i =0;i<ans;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    return 0;
}