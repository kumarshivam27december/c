#include <bits/stdc++.h>
using namespace std;
void rec(int num){
    if(num<1) return;
     cout<<num<<" ";
    rec(num-=1);
   
}
int main()
{
    rec(5);cout<<endl;    
}