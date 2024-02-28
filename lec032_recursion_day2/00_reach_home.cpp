#include <iostream>
using namespace std;
void reachhome(int src,int dest)
{
    cout<<"source "<<src<<" destination "<<dest<<endl;
    //base condition 
    if (src==dest)
    {
        cout<<"reached"<<endl;
        return;
    }

    //processing
    src++;

    // recursive call
    reachhome(src,dest);
    
}
int main()
{
    int src = 1;
    int dest = 10;
    reachhome(src,dest);
    return 0;
}