/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.



Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

*/

#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int remove_element(vector<int> &v){
    int index = 0;
    for(auto element:v){
        if(index<2 || element!=v[index-2]){
            v[index] = element;
            index++;
        }
    }
    return index;
    
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {0,1,1,1,2,2,3};
    int ans = remove_element(v);
    for (int j = 0; j < ans; j++)
    {
        cout<<v[j]<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    return 0;
}