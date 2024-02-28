#include <iostream>
using namespace std;
// int main()
// {
//     /*
//  123
//  456
//  789   
    
//     */

//   int n;
//   cin>>n;
//   int i=1;
//   int k=1;
//   while(i<=n)
//   {
//     int j=1;
    
//     while(j<=n)
//     {
//         cout<<k;
//         k++;
//         j++;
//     }
//     cout<<endl;
//     i++;
//   }


// }

/*

//  123
//  456
//  789  

*/

int main(){
  int n;cin>>n;
  int i = 1;
  int k = 1;
  while(i<=n){
    int j=1;
    while(j<=n){
      cout<<k;
      k++;
      j++;
    }
    cout<<endl;
    i++;
  }
}