#include <bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    int evensum = 0;
    int oddsum = 0;
    while (num)
    {
        int r = num%10;
        num/=10;
        if(r&1){
            oddsum+=r;
        }else{
            evensum+=r;
        }
    }

    cout<<evensum<<" "<<oddsum;
    return 0;
    
}
