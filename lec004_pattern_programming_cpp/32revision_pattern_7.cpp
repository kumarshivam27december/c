/*
1 2 3 4 5 4 3 2 1
1 2 3 4 * 4 3 2 1
1 2 3 * * * 3 2 1
1 2 * * * * * 2 1
1 * * * * * * * 1
*/
/*
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int i = 1;
    while(i<=n)  
    {
        int firsttri = 1;
        while(firsttri<=n-i+1)
        {
            cout<<firsttri<<" ";
            firsttri++;
        }
        int star1 = 1;
        while(star1<=i-1)
        {   cout<<"*"<<" ";
            star1++;
        }
        int star2 = 1;
        while(star2<=i-1)
        {
         cout<<"*"<<" ";
         star2++;   
        }
        int secondtri = n-i+1;
        while(secondtri>=1)
        {
            cout<<secondtri<<" ";
            secondtri--;
        }
        cout<<endl;
        i++;
    }
}


*/
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int i=1;
    while(i<=n)
    {
        int tr1 = 1;
        while(tr1<=n-i+1)
        {
            cout<<tr1<<" ";
            tr1++;
        }
        int str1 = 1;
        while(str1<=i-1)
        {
            cout<<"*"<<" ";
            str1++;
        }
        int str2 = 1;
        while(str2<=i-1)
        {
            cout<<"*"<<" ";
            str2++;
        }
        int tr2 = n-i+1;
        while(tr2>=1)
        {
            cout<<tr2<<" ";
            tr2--;
        }
        cout<<endl;
        i++;
    }
}