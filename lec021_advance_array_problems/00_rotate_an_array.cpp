#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>& nums)
{
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}
void rotate(vector<int>& nums, int k) {
       // just to practice the modulus approach
      int n = nums.size();
      vector<int> temp(n);
      
      
      for(int i =0;i<n;i++) {
        
        temp[(i+k)%n] = nums[i];
        
      }
      
      
      for(int i=0;i<nums.size();i++) 
      {
        nums[i] = temp[i];
      }
      
    }
int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(1);
    v.push_back(6);
    // from how much element it should be rotated
  int k = 3;
    rotate(v,k);
    print(v);

}


