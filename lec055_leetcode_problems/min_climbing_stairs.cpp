#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int climbing(int n){
    //calculate the ways to climb the n number of stairs
    if(n<=2)  return n;
    return 0;
}
int main()
{
    clock_t tStart = clock();
    int stairs = 3;
    cout<<climbing(stairs);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}