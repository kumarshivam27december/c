#include <bits/stdc++.h>
using namespace std;
int totalCandy(vector<int> &rating){
    // if(rating.size()==0) return 0;
    if(rating.size()==1) return 1;
    int l = rating.size();
    vector<int> candies(l,1);

    //left to right  comparing i and i+1
    for (int i = 1; i < l; i++)
    {
        if(rating[i]>rating[i-1] && candies[i]<=candies[i-1]){
            candies[i] = candies[i-1] + 1;
        }
    }
    
    //right to left 
    for(int i = l-2;i>=0;i--){
        if(rating[i+1]<rating[i] && candies[i+1]>=candies[i]){
            candies[i]=candies[i+1]+1;
        }
    }
    int totalCandy = 0;
    for(int i = 0;i<l;i++){
        totalCandy+=candies[i];
    }
    
    return totalCandy;
}
int main(){
    vector <int> rating = {1,0,2};
    cout<<totalCandy(rating)<<endl;
    return 0;
}