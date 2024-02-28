#include <iostream>
#include <cstdio>
using namespace std;

// int main() {
//     int a,b;
//     cin>>a>>b;
//     string num[]={"one","two","three","four","five","six","seven","eight","nine","ten"};
//     for(a;a<=b;a++){
//         if(a>=1 && a<10){
//             cout<<num[a-1]<<endl;
//         }
//         else{
//             if(a%2==0){
//                 cout<<"even"<<endl;
//             }
//             else{
//                 cout<<"odd"<<endl;
//             }
//         }
//     }


//     return 0;
// }

int main(){
    int a,b;
    cin>>a>>b;
    for(a;a<=b;a++){


        if (a==1)
        {
            cout<<"one ";
        }
         if (a==2)
        {
            cout<<"to ";
        } if (a==3)
        {
            cout<<"third ";
        } if (a==4)
        {
            cout<<"for ";
        } if (a==5)
        {
            cout<<"fve ";
        } if (a==6)
        {
            cout<<"six ";
        } if (a==7)
        {
            cout<<"svn ";
        } if (a==8)
        {
            cout<<"eght ";
        } if (a==9)
        {
            cout<<"nine ";
        }
        
        else if(a>9){
                if(a%2==0){
                    cout<<"Even ";
                }else{
                    cout<<"ODD ";
                }
        }
        
    }
}
