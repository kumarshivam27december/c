#include <iostream>
using namespace std;
void print(char name[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<name[i];
    }
}
void reverse(char name[],int n)
{
    int s = 0;
    int e = n-1;
    while (s<=e)
    {
        swap(name[s++],name[e--]);
    }
    
}
int main()
{
    char name[7]="babbar";
    reverse(name,6);
    print(name,6);
}
