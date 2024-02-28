/*

1
01
010
1010


*/
// #include <iostream>
// using namespace std;
// int main(){
//     int m;cin>>m;
//     int k = 1;
//     int i = 1;
//     while (i<=m)
//     {
//         int j=1;
//         while(j<=i){
//             if(k%2==0){
//                 cout<<"0";
//             }else{
//                 cout<<"1";
//             }
//             k++;
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
    
// }


/*

1
01
101
0101
01010

*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j =1;
        while (j<=i)
        {
           if((i+j)%2==0){
            cout<<"1 ";
           }else{
            cout<<"0 ";
           }
           j++;
        }
        cout<<endl;
        i++;
        
    }
}



