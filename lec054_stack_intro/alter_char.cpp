#include <iostream>
#include <string>
using namespace std;
int main()
{
    char ch;
    cin >> ch;
    if (ch>=97 && ch<=122)
    {
        cout<<char(ch-32);
    }else if(ch>=65 && ch<=90){
        cout<<char(ch+32);
    }else{
        cout<<"Invalid input";
    }
    
    return 0;
    
}