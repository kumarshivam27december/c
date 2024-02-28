#include <iostream>
using namespace std;
void printArray(char arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    char ch[5]={'a','s','d','f','g'};
    printArray(ch,5);
}