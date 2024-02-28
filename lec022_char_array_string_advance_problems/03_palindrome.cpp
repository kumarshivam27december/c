#include <iostream>
using namespace std;
int main()
{
    char name[6] = "nbman";
    int s = 0;
    int e = 4;
    bool ans = true;
    while(s<e)
    {
        if(name[s++]!=name[e--])
        {
            ans = false;
        }
        else
        {
            ans = true;
        }
    }

    if(ans)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
}