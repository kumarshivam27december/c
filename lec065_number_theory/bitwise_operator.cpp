#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main()
{
    clock_t tStart = clock();
    int a ,b;
    cin>>a>>b;
    cout<<(a^b)<<endl;
    cout<<(a&b)<<endl;
    cout<<(a|b)<<endl;
    cout<<(~b)<<endl;
    cout<<(~a)<<endl;

    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}

// react
// devops
// autometa maths
 
