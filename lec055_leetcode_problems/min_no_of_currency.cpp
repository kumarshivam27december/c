#include <bits/stdc++.h>
using namespace std;
int min_no_of_notes(int num){
    //complete the code
    int cnt = 0;
    while(num>=2000){
        cnt++;
        num-=2000;
    }
    while(num>=500){
        cnt++;
        num-=500;
    }
    while(num>=200){
        cnt++;
        num-=200;
    }
    while(num>=100){
        cnt++;
        num-=100;
    }
    while(num>=50){
        cnt++;
        num-=50;
    }
    while(num>=20){
        cnt++;
        num-=20;
    }
    while(num>=10){
        cnt++;
        num-=10;
    }
    while(num>=5){
        cnt++;
        num-=5;
    }
    while(num>=2){
        cnt++;
        num-=2;
    }
    while(num>=1){
        cnt++;
        num-=1;
    }
    return cnt;
    
}
int main(){
    int num = 1638;
    cout<<min_no_of_notes(num)<<endl;
    return 0;
}