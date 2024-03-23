#include <bits/stdc++.h>
using namespace std;
int final(int left,int right){
    int count = 0;
    while(left!= right){
        left = left>>1;
        right= right>>1;
        count++;
    }
    return left<<count;
}
int main(){
    int k = 20;
    int l = 23;
    int result = final(k,l);
    cout<<result<<endl;
    return 0;
}