#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int power(int base,int exp){
    if(exp<1) return 1;

    return base*power(base,exp-1);
}
int main()
{
    clock_t tStart = clock();
    cout<<power(2,5);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}