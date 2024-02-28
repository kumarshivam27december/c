#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    bool ispoweroftwo = false;

    for (int i = 0; i < 30; i++)
    {
        int ans=pow(2,i);
        if(ans==n)
        {
            ispoweroftwo  = true;
            break;
            
        }

        
    }
        
            cout<<ispoweroftwo<<endl;
  

}