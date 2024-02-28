#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int>& nums) 
{
    int count  = 0;
    int n = nums.size();
    for(int i=1;i<n;i++) 
    {
        if(nums[i] < nums[i-1])
            count++;
    }
    if(nums[n-1] > nums[0])
        count++;
        
    return count<=1;
}
int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(1);
    v.push_back(6);

    int ans = check(v);
    if(ans)
    {
        cout<<" it is sorted and rotated array "<<endl;
    }
    else
    {
        cout<<"it is not sorted and rotated "<<endl;
    }

}
