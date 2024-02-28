#include <iostream>
using namespace std;

int main() {

/*

A A A
B B B
c c c

*/

int n;
cin>>n;
int row=1;

while(row<=n)
{
    
    int col=1;
    char ch='A';
    while(col<=n)
    {
        cout<<ch<<" ";
        ch++;
        col++;
    }
    
    cout<<endl;
    row++;
}
}
