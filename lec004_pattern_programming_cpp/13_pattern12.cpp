#include <iostream>
using namespace std;

int main() {

/*

A B C
B C D
C D F


*/

int n;
cin>>n;
int row=1;

while(row<=n)
{
    int k=row;
    int col=1;
    while(col<=n)
    {
        
        cout<<char(k+64)<<" ";
        k++;
        col++;
    }
    cout<<endl;
    row++;
}
}
