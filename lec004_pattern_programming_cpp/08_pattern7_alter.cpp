#include <iostream>
using namespace std;

int main() {

/*

1
2 3
3 4 5 
4 5 6 7

*/

int n;
cin>>n;
int row=1;
while(row<=n)
{
    int column=row;
    while(column<row*2)
    {
        cout<<column<<" ";
        column++;
    }
    cout<<endl;
    row++;
}

}


