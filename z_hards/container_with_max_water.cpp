#include <bits/stdc++.h>
using namespace std;
int container_with_max_water(vector<int> &heights){
    int sizes = heights.size();
    int left = 0;
    int right = sizes-1;
    int maxArea = 0;
    while (left<right)
    {
        int area = min(heights[left],heights[right])*(right-left);
        maxArea = max(area,maxArea);
        if(heights[left]<heights[right]){
            left++;
        }else{
            right--;
        }
    }
    return maxArea;
    
}
int main()
{ 
    vector <int> heights = {1,8,6,2,5,4,8,3,7};
    cout<<container_with_max_water(heights)<<endl;
    return 0;
}