#include <iostream>
using namespace std;
int main()
{
    int n=5;
    int i=1;
    for(;;)
    {
        if(i<=n)
        {
            cout<<i<<endl;
        }
         //doesn't know when to stop

    // hence we use break statement 
    else{
        break;
    }
        i++;
       
    }

    
}