#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int count_divisor(int n){
    unordered_map<int,int>mp;
    for(int i = 2;i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n=n/i;
        }
    }

   return mp.size();
}
void findcout(int n){
    unordered_map<int,int>mp;
    for(int i = 2;i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n=n/i;
        }
    }
    

    int product = 1;
    for(auto i : mp){        
        product*=(i.second+1);
    }

    cout<<product<<endl;
}
void findsum(int n){

}
void findproduct(int n){

}
int main()
{
    clock_t tStart = clock();
    int n;
    cin>>n;
    findcout(n);
    findsum(n);
    findproduct(n);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}