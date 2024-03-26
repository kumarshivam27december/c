#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m,a;
    cin>>n>>m>>a;
    long long int len = n/a;
    if((n%a)!=0){
        len++;
    }
    long long int bre =m/a;
    if((m%a)!=0){
        bre++;
    }
    cout<<len*bre<<endl;
    return 0;
}