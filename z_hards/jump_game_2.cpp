#include <bits/stdc++.h>
using namespace std;
int minimum_jump(vector<int>& v){
    int n = v.size();
    if (n == 1) return 0;
    
   int jump = 0;
   int farthest = 0;
   int current = 0;
   for (int i = 0; i < v.size()-1; i++)
   {
        farthest = max(farthest,v[i]+i);
        if(i==current){
            current = farthest;
            jump++;
        }

   }
   return jump;
}
int main(){
    vector<int> v = {2,3,1,1,4};
    cout<<minimum_jump(v)<<endl;
    return 0;
}