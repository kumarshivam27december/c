// #include <iostream>
// using namespace std;

// int main() {

// /*

// A B C
// D E F
// G H I

// */

// int n;
// cin>>n;
// int row=1;
// char ch='A';
// while(row<=n)
// {
    
//     int col=1;
    
//     while(col<=n)
//     {
//         cout<<ch<<" ";
//         ch++;
//         col++;
//     }
    
//     cout<<endl;
//     row++;
// }
// }


#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char print = 'A';
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=n){
            cout<<print<<" ";
            j++;
            print++;
        }
        cout<<endl;
        i++;
    }
}


