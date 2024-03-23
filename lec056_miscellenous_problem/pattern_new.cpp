#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int k = 1;
        while(k<=i){
            if(i%2==0){
                cout<<"0"<<" ";
                k++;
            }else{
                cout<<"1"<<" ";
                k++;
            }
            
        }
        cout<<endl;
        i++;
    }
}