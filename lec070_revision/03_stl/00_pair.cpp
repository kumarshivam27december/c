#include <bits/stdc++.h>
using namespace std;
int main() {
    pair<int,string> p;
    p = make_pair(1,"123");
    cout<<p.first<<" "<<p.second;


    //arrays pair
    /*
    arr1 = [1,2,3];
    arr2=[2,3,4];
    now if we have to make a relation between them so that when key changed value must
    be changed
    then we use pair
    
    */

   cout<<endl;
   pair<int,int> p_array[3];
   p_array[0] = {1,2};
   p_array[1] = {2,3};
   p_array[2] = {3,4};


   for(int i = 0;i<3;i++){
    cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
   }

   swap(p_array[0],p_array[2]);

    for(int i = 0;i<3;i++){
    cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
   }


    /*
    we basically use it to maintain the relation
    */

   //we even can take input pair

   pair<int,char>p2;
   cin>>p2.first;
   cin>>p2.second;

   cout<<p2.first<<" "<<p2.second<<endl;



}