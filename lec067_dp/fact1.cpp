#include <iostream>
using namespace std;
int find(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    
    return n*find(n-1);
}
int main(){
    int n=5;
    cout<<find(n);
    return 0;
}