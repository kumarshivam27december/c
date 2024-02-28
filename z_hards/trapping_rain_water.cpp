#include <bits/stdc++.h>
using namespace std;
int totalWater(vector<int>&heights){
    int sizes = heights.size();
    vector<int> left(sizes,0);
    left[0] = heights[0];
    for (int i = 1; i < sizes; i++)
    {
        left[i] = max(left[i-1],heights[i]);
    }
    
    vector<int> right(sizes,0);
    right[sizes-1]=heights[sizes-1];
    for (int i = sizes-2; i >=0; i--)
    {
        right[i] = max(right[i+1],heights[i]);
    }

    int total = 0;
    for (int i = 0; i < sizes; i++)
    {
        total+=((min(left[i],right[i]))-heights[i]);
    }
    return total;
}
int main(){
    vector<int> heights = {3,2,0,1,4,5,3};
    cout<<totalWater(heights)<<endl;
    return 0;
}