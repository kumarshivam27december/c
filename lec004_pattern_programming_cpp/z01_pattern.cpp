#include <iostream>
using namespace std;
/*

****
***
**
*

int main(){
    int n;
    cin>>n;
    for (int i = n; i >0; i--)
    {
       for (int j = i; j >0; j--)
       {
        cout<<"*";
       }cout<<endl;
       
    }
    
}



*/


/*

   *
  **
 ***
****

int main() {
    int rows = 4;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


//ALTER


int main(){
    int n;cin>>n;
    int i = 1;
    while (i<=n)
    {
        int space = n-i;
        while (space)
        {
            cout<<"   ";
            space--;
        }

        int j = 1;
        while (j<=i)
        {
            cout<<" * ";
            j++;
        }
        cout<<endl;
        i++;
        
    }
    
}


*/
