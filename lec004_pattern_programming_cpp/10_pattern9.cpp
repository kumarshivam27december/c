#include <iostream>
using namespace std;

// int main() {



// int n;
// cin>>n;
// char ch='A';
// int row=1;
// while(row<=n)
// {
//     int col=1;
//     while(col<=n)
//     {
//         cout<<ch<<" ";
        
//         col++;
//     }
//     cout<<endl;
//     ch++;
//     row++;
// }

// }

/*

A A A
B B B
c c c

*/

int main(){
    int n;
    cin>>n;
    char to_print = 'A';
    int i=1;
    while(i<=n){
        int j =1;
        while(j<=n){
            cout<<to_print<<" ";
            j++;
        }
        cout<<endl;
        to_print++;
        i++;
    }
}