#include <iostream>
using namespace std;
int product(int a,int b){
    if(b<1){
        return 0;
    }
    if(b==1){
        return a;
    }
    return a+product(a,b-1);
}
int main(){
    int a,b;
    a = 20;
    b = 10000;
    cout<<product(a,b)<<endl;
    return 0;
}