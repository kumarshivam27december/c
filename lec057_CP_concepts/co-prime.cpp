#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    //base case
    if(a==b){
        return a;
    }
    if(a<b){
        return gcd(a,b-a);
    }

    return gcd(a-b,b);

}
int main(){
    int a=5;
    int b = 10;
    if(gcd(a,b)==1){
        cout<<"Yes it is co-prime";
    }else{
        cout<<"No,it is not co-prime";
    }
    return 0;
}